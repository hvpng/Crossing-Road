#include "Vehicle.h"

CVEHICLE::CVEHICLE(sf::Vector2f position, sf::Vector2f size, float speed, int lane, int direction, sf::Color color)
    : CEntity(position, size, speed), m_lane(lane), m_direction(direction), m_color(color) {
}

void CVEHICLE::setStopped(bool stopped) {
    m_stoppedByRedLight = stopped;
}

void CVEHICLE::update(float dt) {
    if (m_stoppedByRedLight) {
        return;
    }

    m_position.x += m_speed * static_cast<float>(m_direction) * dt;
    if (m_direction > 0 && m_position.x > cfg::PlayWidth + 40.f) {
        m_position.x = -m_size.x;
    } else if (m_direction < 0 && m_position.x + m_size.x < -40.f) {
        m_position.x = cfg::PlayWidth + m_size.x;
    }
}

void CVEHICLE::draw(sf::RenderWindow& window) const {
    sf::RectangleShape body(m_size);
    body.setPosition(m_position);
    body.setFillColor(m_color);
    body.setOutlineThickness(3.f);
    body.setOutlineColor(sf::Color(30, 30, 35));
    window.draw(body);

    sf::RectangleShape windowRect({m_size.x * 0.32f, m_size.y * 0.36f});
    windowRect.setPosition(m_position.x + m_size.x * 0.18f, m_position.y + m_size.y * 0.15f);
    windowRect.setFillColor(sf::Color(190, 235, 255));
    window.draw(windowRect);
}

CTRUCK::CTRUCK(sf::Vector2f position, int lane, int direction)
    : CVEHICLE(position, {112.f, 42.f}, 150.f, lane, direction, sf::Color(210, 70, 58)) {
}

CCAR::CCAR(sf::Vector2f position, int lane, int direction)
    : CVEHICLE(position, {78.f, 38.f}, 210.f, lane, direction, sf::Color(64, 160, 255)) {
}
