#include "Animal.h"

CANIMAL::CANIMAL(sf::Vector2f position, sf::Vector2f size, float speed, int lane, int direction, sf::Color color)
    : CEntity(position, size, speed), m_lane(lane), m_direction(direction), m_color(color) {
}

void CANIMAL::update(float dt) {
    m_position.x += m_speed * static_cast<float>(m_direction) * dt;
    if (m_direction > 0 && m_position.x > cfg::PlayWidth + 40.f) {
        m_position.x = -m_size.x;
    } else if (m_direction < 0 && m_position.x + m_size.x < -40.f) {
        m_position.x = cfg::PlayWidth + m_size.x;
    }
}

void CANIMAL::draw(sf::RenderWindow& window) const {
    sf::CircleShape body(m_size.y * 0.45f, 6);
    body.setPosition(m_position);
    body.setScale(m_size.x / m_size.y, 1.f);
    body.setFillColor(m_color);
    body.setOutlineThickness(3.f);
    body.setOutlineColor(sf::Color(40, 35, 30));
    window.draw(body);
}

CDINAUSOR::CDINAUSOR(sf::Vector2f position, int lane, int direction)
    : CANIMAL(position, {92.f, 46.f}, 135.f, lane, direction, sf::Color(112, 195, 88)) {
}

CBIRD::CBIRD(sf::Vector2f position, int lane, int direction)
    : CANIMAL(position, {72.f, 34.f}, 245.f, lane, direction, sf::Color(245, 205, 80)) {
}
