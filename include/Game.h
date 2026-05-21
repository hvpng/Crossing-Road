#pragma once

#include "Animal.h"
#include "People.h"
#include "SharedState.h"
#include "TrafficLight.h"
#include "Vehicle.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <memory>
#include <string>
#include <vector>

class CGAME {
public:
    explicit CGAME(SharedState& shared);

    void processInput();
    void update(float dt);
    void drawGame(sf::RenderWindow& window);
    void restart();
    void saveGame();
    void loadGame(const std::filesystem::path& file);
    std::vector<std::filesystem::path> listSaveFiles() const;

private:
    void createLevel();
    void drawMainMenu(sf::RenderWindow& window);
    void drawMapSelect(sf::RenderWindow& window);
    void drawNameInput(sf::RenderWindow& window);
    void drawPlaying(sf::RenderWindow& window);
    void drawPauseMenu(sf::RenderWindow& window);
    void drawLoadGame(sf::RenderWindow& window);
    void drawSetting(sf::RenderWindow& window);
    void drawHelp(sf::RenderWindow& window);
    void drawText(sf::RenderWindow& window, const std::string& text, sf::Vector2f pos, unsigned size, sf::Color color = sf::Color::White);

    SharedState& m_shared;
    CPEOPLE m_people;
    CTRAFFICLIGHT m_trafficLight;
    std::vector<std::unique_ptr<CVEHICLE>> m_vehicles;
    std::vector<std::unique_ptr<CANIMAL>> m_animals;
    sf::Font m_font;
    std::string m_playerName = "Player";
    int m_score = 0;
    int m_level = 0;
    int m_selectedMap = 0;
    float m_collisionEffect = 0.f;
};
