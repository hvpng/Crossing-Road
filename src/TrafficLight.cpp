#include "TrafficLight.h"

void CTRAFFICLIGHT::update(float dt) {
    m_timer += dt;

    if (m_state == LightState::Green && m_timer >= 4.f) {
        m_state = LightState::Red;
        m_timer = 0.f;
    } else if (m_state == LightState::Red && m_timer >= 2.f) {
        m_state = LightState::Green;
        m_timer = 0.f;
    }
}

void CTRAFFICLIGHT::draw(sf::RenderWindow& window) const {
    sf::RectangleShape pole({16.f, 82.f});
    pole.setPosition({cfg::PlayWidth - 54.f, 74.f});
    pole.setFillColor(sf::Color(60, 63, 70));
    window.draw(pole);

    sf::RectangleShape box({44.f, 78.f});
    box.setPosition({cfg::PlayWidth - 68.f, 44.f});
    box.setFillColor(sf::Color(32, 34, 40));
    window.draw(box);

    sf::CircleShape red(13.f);
    red.setPosition({cfg::PlayWidth - 53.f, 52.f});
    red.setFillColor(isRed() ? sf::Color(255, 55, 55) : sf::Color(90, 30, 30));
    window.draw(red);

    sf::CircleShape green(13.f);
    green.setPosition({cfg::PlayWidth - 53.f, 86.f});
    green.setFillColor(isRed() ? sf::Color(25, 75, 30) : sf::Color(70, 235, 95));
    window.draw(green);
}

bool CTRAFFICLIGHT::isRed() const {
    return m_state == LightState::Red;
}

LightState CTRAFFICLIGHT::getState() const {
    return m_state;
}
