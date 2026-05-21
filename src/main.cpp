#include "Game.h"
#include "SharedState.h"
#include <SFML/Graphics.hpp>
#include <atomic>
#include <chrono>
#include <thread>

namespace {
void setScene(SharedState& shared, Scene scene) {
    std::lock_guard<std::mutex> lock(shared.mutex);
    shared.scene = scene;
    shared.isPaused = scene == Scene::PauseMenu;
    shared.menuIndex = 0;
}

void clampMenu(SharedState& shared, int maxItems) {
    if (shared.menuIndex < 0) {
        shared.menuIndex = maxItems - 1;
    }
    if (shared.menuIndex >= maxItems) {
        shared.menuIndex = 0;
    }
}

void handleMenuEnter(SharedState& shared) {
    std::lock_guard<std::mutex> lock(shared.mutex);
    if (shared.scene == Scene::MainMenu) {
        if (shared.menuIndex == 0) shared.scene = Scene::MapSelect;
        if (shared.menuIndex == 1) shared.scene = Scene::LoadGame;
        if (shared.menuIndex == 2) shared.scene = Scene::Setting;
        if (shared.menuIndex == 3) {
            shared.scene = Scene::Quit;
            shared.isRunning = false;
        }
        shared.menuIndex = 0;
        return;
    }

    if (shared.scene == Scene::PauseMenu) {
        if (shared.menuIndex == 0) {
            shared.scene = Scene::Playing;
            shared.isPaused = false;
        } else if (shared.menuIndex == 1) {
            shared.requestRestart = true;
            shared.scene = Scene::Playing;
            shared.isPaused = false;
        } else if (shared.menuIndex == 2) {
            shared.requestSave = true;
        } else if (shared.menuIndex == 3) {
            shared.scene = Scene::Setting;
        } else if (shared.menuIndex == 4) {
            shared.scene = Scene::Help;
        } else if (shared.menuIndex == 5) {
            shared.scene = Scene::Quit;
            shared.isRunning = false;
        }
        shared.menuIndex = 0;
    }
}
}

void SubThread(sf::RenderWindow& window, SharedState& shared) {
    window.setActive(true);
    CGAME game(shared);
    sf::Clock frameClock;

    while (true) {
        {
            std::lock_guard<std::mutex> lock(shared.mutex);
            if (!shared.isRunning) {
                break;
            }
        }

        const float dt = frameClock.restart().asSeconds();
        game.processInput();
        game.update(dt);
        game.drawGame(window);

        const auto elapsed = frameClock.getElapsedTime();
        const auto target = sf::seconds(cfg::TargetFrameSeconds);
        if (elapsed < target) {
            sf::sleep(target - elapsed);
        }
    }

    window.setActive(false);
}

int main() {
    SharedState shared;

    sf::RenderWindow window(
        sf::VideoMode(cfg::WindowWidth, cfg::WindowHeight),
        "Crossing Game",
        sf::Style::Fullscreen);
    window.setFramerateLimit(0);
    window.setVerticalSyncEnabled(true);

    // The main thread owns events; the sub-thread owns rendering/updating.
    window.setActive(false);
    std::thread worker(SubThread, std::ref(window), std::ref(shared));

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                std::lock_guard<std::mutex> lock(shared.mutex);
                shared.isRunning = false;
                window.close();
            }

            if (event.type == sf::Event::TextEntered) {
                std::lock_guard<std::mutex> lock(shared.mutex);
                if (shared.scene == Scene::NameInput) {
                    if (event.text.unicode == 8 && !shared.playerName.empty()) {
                        shared.playerName.pop_back();
                    } else if (event.text.unicode >= 32 && event.text.unicode < 127 && shared.playerName.size() < 18) {
                        shared.playerName.push_back(static_cast<char>(event.text.unicode));
                    }
                }
            }

            if (event.type != sf::Event::KeyPressed) {
                continue;
            }

            const auto key = event.key.code;
            {
                std::lock_guard<std::mutex> lock(shared.mutex);

                if (key == sf::Keyboard::Escape) {
                    if (shared.scene == Scene::Playing) {
                        shared.scene = Scene::PauseMenu;
                        shared.isPaused = true;
                    } else if (shared.scene != Scene::MainMenu) {
                        shared.scene = Scene::MainMenu;
                        shared.isPaused = false;
                    }
                }

                if (key == sf::Keyboard::P && (shared.scene == Scene::Playing || shared.scene == Scene::PauseMenu)) {
                    shared.isPaused = !shared.isPaused;
                    shared.scene = shared.isPaused ? Scene::PauseMenu : Scene::Playing;
                }

                if (shared.scene == Scene::Playing) {
                    if (key == sf::Keyboard::W) shared.moving = Direction::Up;
                    if (key == sf::Keyboard::A) shared.moving = Direction::Left;
                    if (key == sf::Keyboard::S) shared.moving = Direction::Down;
                    if (key == sf::Keyboard::D) shared.moving = Direction::Right;
                }

                if (shared.scene == Scene::MainMenu || shared.scene == Scene::PauseMenu) {
                    const int maxItems = shared.scene == Scene::MainMenu ? 4 : 6;
                    if (key == sf::Keyboard::Up) shared.menuIndex--;
                    if (key == sf::Keyboard::Down) shared.menuIndex++;
                    clampMenu(shared, maxItems);
                }

                if (shared.scene == Scene::MapSelect) {
                    if (key == sf::Keyboard::Up) shared.selectedMap = (shared.selectedMap + 2) % 3;
                    if (key == sf::Keyboard::Down) shared.selectedMap = (shared.selectedMap + 1) % 3;
                    if (key == sf::Keyboard::Enter) shared.scene = Scene::NameInput;
                } else if (shared.scene == Scene::NameInput && key == sf::Keyboard::Enter) {
                    shared.scene = Scene::Playing;
                    shared.isPaused = false;
                } else if (shared.scene == Scene::Setting) {
                    if (key == sf::Keyboard::B) shared.bgmEnabled = !shared.bgmEnabled;
                    if (key == sf::Keyboard::S) shared.sfxEnabled = !shared.sfxEnabled;
                }
            }

            if (key == sf::Keyboard::Enter) {
                handleMenuEnter(shared);
            }
        }

        {
            std::lock_guard<std::mutex> lock(shared.mutex);
            if (!shared.isRunning) {
                window.close();
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    {
        std::lock_guard<std::mutex> lock(shared.mutex);
        shared.isRunning = false;
    }

    if (worker.joinable()) {
        worker.join();
    }

    return 0;
}
