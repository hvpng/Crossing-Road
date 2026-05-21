#include "Game.h"
#include <fstream>
#include <iomanip>
#include <sstream>

CGAME::CGAME(SharedState& shared)
    : m_shared(shared) {
    m_font.loadFromFile("assets/fonts/arial.ttf");
    createLevel();
}

void CGAME::processInput() {
    Direction move = Direction::None;
    bool restart = false;
    bool save = false;
    bool paused = false;
    std::string name;
    int selectedMap = 0;

    {
        std::lock_guard<std::mutex> lock(m_shared.mutex);
        move = m_shared.moving;
        m_shared.moving = Direction::None;
        restart = m_shared.requestRestart;
        m_shared.requestRestart = false;
        save = m_shared.requestSave;
        m_shared.requestSave = false;
        paused = m_shared.isPaused;
        name = m_shared.playerName;
        selectedMap = m_shared.selectedMap;
    }

    m_playerName = name.empty() ? "Player" : name;
    m_selectedMap = selectedMap;

    if (restart) {
        restart = false;
        this->restart();
    }
    if (save) {
        saveGame();
    }
    if (!paused) {
        m_people.moveByTile(move);
    }
}

void CGAME::update(float dt) {
    bool paused = false;
    {
        std::lock_guard<std::mutex> lock(m_shared.mutex);
        paused = m_shared.isPaused || m_shared.scene != Scene::Playing;
    }

    if (paused) {
        return;
    }

    m_trafficLight.update(dt);
    const bool redLight = m_trafficLight.isRed();

    for (auto& vehicle : m_vehicles) {
        vehicle->setStopped(redLight);
        vehicle->update(dt);
    }
    for (auto& animal : m_animals) {
        animal->update(dt);
    }

    m_people.update(dt);
    if (m_collisionEffect > 0.f) {
        m_collisionEffect -= dt;
    }

    for (const auto& vehicle : m_vehicles) {
        if (m_people.isImpact(*vehicle)) {
            m_people.kill();
            m_collisionEffect = 1.2f;
        }
    }
    for (const auto& animal : m_animals) {
        if (m_people.isImpact(*animal)) {
            m_people.kill();
            m_collisionEffect = 1.2f;
        }
    }

    if (!m_people.isAlive() && m_collisionEffect <= 0.f) {
        m_people.reset();
    }

    if (m_people.isFinish()) {
        m_score += 100;
        m_level = (m_level + 1) % (cfg::MaxLevel + 1);
        m_people.reset();
        createLevel();
    }
}

void CGAME::drawGame(sf::RenderWindow& window) {
    Scene scene = Scene::MainMenu;
    {
        std::lock_guard<std::mutex> lock(m_shared.mutex);
        scene = m_shared.scene;
    }

    window.clear(sf::Color(18, 20, 28));

    switch (scene) {
    case Scene::MainMenu:
        drawMainMenu(window);
        break;
    case Scene::MapSelect:
        drawMapSelect(window);
        break;
    case Scene::NameInput:
        drawNameInput(window);
        break;
    case Scene::Playing:
        drawPlaying(window);
        break;
    case Scene::PauseMenu:
        drawPlaying(window);
        drawPauseMenu(window);
        break;
    case Scene::LoadGame:
        drawLoadGame(window);
        break;
    case Scene::Setting:
        drawSetting(window);
        break;
    case Scene::Help:
        drawHelp(window);
        break;
    case Scene::Quit:
        break;
    }

    window.display();
}

void CGAME::restart() {
    m_score = 0;
    m_level = 0;
    m_collisionEffect = 0.f;
    m_people.reset();
    createLevel();
}

void CGAME::saveGame() {
    std::filesystem::create_directories("save");
    std::ofstream out("save/" + m_playerName + ".sav");
    out << m_playerName << '\n' << m_score << '\n' << m_level << '\n' << m_selectedMap << '\n';
}

void CGAME::loadGame(const std::filesystem::path& file) {
    std::ifstream in(file);
    if (!in) {
        return;
    }
    std::getline(in, m_playerName);
    in >> m_score >> m_level >> m_selectedMap;
    {
        std::lock_guard<std::mutex> lock(m_shared.mutex);
        m_shared.playerName = m_playerName;
        m_shared.selectedMap = m_selectedMap;
    }
    createLevel();
}

std::vector<std::filesystem::path> CGAME::listSaveFiles() const {
    std::vector<std::filesystem::path> files;
    if (!std::filesystem::exists("save")) {
        return files;
    }

    for (const auto& entry : std::filesystem::directory_iterator("save")) {
        if (entry.is_regular_file() && entry.path().extension() == ".sav") {
            files.push_back(entry.path());
        }
    }
    return files;
}

void CGAME::createLevel() {
    m_vehicles.clear();
    m_animals.clear();

    const float firstLane = 150.f;
    for (int i = 0; i < 4; ++i) {
        const float y = firstLane + static_cast<float>(i) * cfg::LaneHeight;
        const int direction = (i % 2 == 0) ? 1 : -1;
        m_vehicles.push_back(std::make_unique<CCAR>(sf::Vector2f(80.f + i * 190.f, y), i, direction));
        m_vehicles.push_back(std::make_unique<CTRUCK>(sf::Vector2f(410.f + i * 170.f, y + 34.f), i, direction));
    }

    m_animals.push_back(std::make_unique<CDINAUSOR>(sf::Vector2f(160.f, 104.f), 0, 1));
    m_animals.push_back(std::make_unique<CBIRD>(sf::Vector2f(720.f, 586.f), 3, -1));
}

void CGAME::drawMainMenu(sf::RenderWindow& window) {
    drawText(window, "CROSSING GAME", {330.f, 100.f}, 54, sf::Color(255, 236, 120));
    const char* items[] = {"New Game", "Load Game", "Setting", "Quit"};
    int index = 0;
    {
        std::lock_guard<std::mutex> lock(m_shared.mutex);
        index = m_shared.menuIndex;
    }
    for (int i = 0; i < 4; ++i) {
        sf::RectangleShape button({360.f, 58.f});
        button.setPosition(450.f, 230.f + i * 82.f);
        button.setFillColor(i == index ? sf::Color(80, 130, 210) : sf::Color(45, 50, 65));
        button.setOutlineThickness(3.f);
        button.setOutlineColor(sf::Color(180, 190, 210));
        window.draw(button);
        drawText(window, items[i], {520.f, 242.f + i * 82.f}, 28);
    }
}

void CGAME::drawMapSelect(sf::RenderWindow& window) {
    drawText(window, "SELECT MAP", {80.f, 55.f}, 42, sf::Color(255, 236, 120));
    const char* names[] = {"City", "Ocean / Sky", "Space"};
    const char* desc[] = {"Cars, trucks and traffic lights.", "Birds and fast moving air lanes.", "Ships, comets and low gravity lanes."};
    int selected = 0;
    {
        std::lock_guard<std::mutex> lock(m_shared.mutex);
        selected = m_shared.selectedMap;
    }
    for (int i = 0; i < 3; ++i) {
        sf::RectangleShape panel({1030.f, 132.f});
        panel.setPosition(90.f, 150.f + i * 158.f);
        panel.setFillColor(i == selected ? sf::Color(65, 100, 160) : sf::Color(38, 43, 58));
        panel.setOutlineThickness(3.f);
        panel.setOutlineColor(sf::Color(150, 164, 190));
        window.draw(panel);
        drawText(window, names[i], {130.f, 170.f + i * 158.f}, 30);
        drawText(window, desc[i], {130.f, 216.f + i * 158.f}, 20, sf::Color(220, 224, 235));

        sf::RectangleShape sprite({118.f, 64.f});
        sprite.setPosition(930.f, 184.f + i * 158.f);
        sprite.setFillColor(i == 0 ? sf::Color(210, 70, 58) : (i == 1 ? sf::Color(245, 205, 80) : sf::Color(160, 120, 240)));
        window.draw(sprite);
    }
}

void CGAME::drawNameInput(sf::RenderWindow& window) {
    std::string name;
    {
        std::lock_guard<std::mutex> lock(m_shared.mutex);
        name = m_shared.playerName;
    }
    drawText(window, "ENTER PLAYER NAME", {350.f, 180.f}, 40, sf::Color(255, 236, 120));
    sf::RectangleShape input({520.f, 74.f});
    input.setPosition(370.f, 310.f);
    input.setFillColor(sf::Color(32, 36, 48));
    input.setOutlineThickness(4.f);
    input.setOutlineColor(sf::Color(130, 170, 230));
    window.draw(input);
    drawText(window, name + "_", {394.f, 326.f}, 30);
    drawText(window, "Press Enter to start", {500.f, 420.f}, 22, sf::Color(210, 216, 228));
}

void CGAME::drawPlaying(sf::RenderWindow& window) {
    sf::RectangleShape playArea({cfg::PlayWidth, static_cast<float>(cfg::WindowHeight)});
    playArea.setFillColor(sf::Color(42, 118, 86));
    window.draw(playArea);

    for (int i = 0; i < 4; ++i) {
        sf::RectangleShape lane({cfg::PlayWidth, cfg::LaneHeight - 8.f});
        lane.setPosition(0.f, 138.f + i * cfg::LaneHeight);
        lane.setFillColor(sf::Color(54, 58, 68));
        window.draw(lane);
    }

    m_trafficLight.draw(window);
    for (const auto& vehicle : m_vehicles) {
        vehicle->draw(window);
    }
    for (const auto& animal : m_animals) {
        animal->draw(window);
    }
    m_people.draw(window);

    if (m_collisionEffect > 0.f) {
        sf::CircleShape flash(70.f);
        flash.setPosition(m_people.getPosition().x - 50.f, m_people.getPosition().y - 50.f);
        flash.setFillColor(sf::Color(255, 90, 80, 90));
        window.draw(flash);
    }

    sf::RectangleShape sidebar({cfg::SidebarWidth, static_cast<float>(cfg::WindowHeight)});
    sidebar.setPosition(cfg::PlayWidth, 0.f);
    sidebar.setFillColor(sf::Color(25, 28, 38));
    window.draw(sidebar);
    drawText(window, "PLAYER", {cfg::PlayWidth + 28.f, 70.f}, 20, sf::Color(145, 160, 190));
    drawText(window, m_playerName, {cfg::PlayWidth + 28.f, 100.f}, 28);
    drawText(window, "SCORE", {cfg::PlayWidth + 28.f, 180.f}, 20, sf::Color(145, 160, 190));
    drawText(window, std::to_string(m_score), {cfg::PlayWidth + 28.f, 210.f}, 34, sf::Color(255, 236, 120));
    drawText(window, "LEVEL", {cfg::PlayWidth + 28.f, 300.f}, 20, sf::Color(145, 160, 190));
    drawText(window, std::to_string(m_level) + "/" + std::to_string(cfg::MaxLevel), {cfg::PlayWidth + 28.f, 330.f}, 34);
    drawText(window, m_trafficLight.isRed() ? "RED LIGHT" : "GREEN LIGHT", {cfg::PlayWidth + 28.f, 430.f}, 24,
             m_trafficLight.isRed() ? sf::Color(255, 90, 90) : sf::Color(90, 235, 105));
}

void CGAME::drawPauseMenu(sf::RenderWindow& window) {
    sf::RectangleShape overlay({static_cast<float>(cfg::WindowWidth), static_cast<float>(cfg::WindowHeight)});
    overlay.setFillColor(sf::Color(0, 0, 0, 145));
    window.draw(overlay);

    sf::RectangleShape popup({430.f, 470.f});
    popup.setPosition(420.f, 120.f);
    popup.setFillColor(sf::Color(34, 38, 52));
    popup.setOutlineThickness(4.f);
    popup.setOutlineColor(sf::Color(210, 220, 235));
    window.draw(popup);

    drawText(window, "PAUSED", {542.f, 145.f}, 42, sf::Color(255, 236, 120));
    const char* items[] = {"RESUME", "RESTART", "SAVE", "SETTING", "HELP", "QUIT"};
    int index = 0;
    {
        std::lock_guard<std::mutex> lock(m_shared.mutex);
        index = m_shared.menuIndex;
    }
    for (int i = 0; i < 6; ++i) {
        drawText(window, std::string(i == index ? "> " : "  ") + items[i], {515.f, 222.f + i * 50.f}, 25);
    }
}

void CGAME::drawLoadGame(sf::RenderWindow& window) {
    drawText(window, "LOAD GAME", {85.f, 60.f}, 42, sf::Color(255, 236, 120));
    auto files = listSaveFiles();
    if (files.empty()) {
        drawText(window, "No Saved Games Found", {410.f, 330.f}, 32, sf::Color(255, 120, 120));
        drawText(window, "Press Esc to return", {500.f, 385.f}, 22, sf::Color(220, 224, 235));
        return;
    }
    for (std::size_t i = 0; i < files.size(); ++i) {
        drawText(window, files[i].filename().string(), {140.f, 150.f + i * 42.f}, 24);
    }
}

void CGAME::drawSetting(sf::RenderWindow& window) {
    bool bgm = true;
    bool sfx = true;
    {
        std::lock_guard<std::mutex> lock(m_shared.mutex);
        bgm = m_shared.bgmEnabled;
        sfx = m_shared.sfxEnabled;
    }
    drawText(window, "SETTING", {85.f, 60.f}, 42, sf::Color(255, 236, 120));
    drawText(window, "Background Music: " + std::string(bgm ? "ON" : "OFF"), {170.f, 210.f}, 30);
    drawText(window, "SFX: " + std::string(sfx ? "ON" : "OFF"), {170.f, 270.f}, 30);
    drawText(window, "Press B/S to toggle, Esc to return", {170.f, 360.f}, 22, sf::Color(220, 224, 235));
}

void CGAME::drawHelp(sf::RenderWindow& window) {
    drawText(window, "HELP", {85.f, 60.f}, 42, sf::Color(255, 236, 120));
    drawText(window, "W A S D: Move", {180.f, 180.f}, 28);
    drawText(window, "P: Pause / Resume", {180.f, 230.f}, 28);
    drawText(window, "Enter: Select", {180.f, 280.f}, 28);
    drawText(window, "Esc: Back", {180.f, 330.f}, 28);
}

void CGAME::drawText(sf::RenderWindow& window, const std::string& text, sf::Vector2f pos, unsigned size, sf::Color color) {
    if (!m_font.getInfo().family.empty()) {
        sf::Text sfText(text, m_font, size);
        sfText.setPosition(pos);
        sfText.setFillColor(color);
        window.draw(sfText);
        return;
    }

    sf::RectangleShape fallback({static_cast<float>(text.size() * size) * 0.35f, static_cast<float>(size)});
    fallback.setPosition(pos);
    fallback.setFillColor(sf::Color(color.r, color.g, color.b, 120));
    window.draw(fallback);
}
