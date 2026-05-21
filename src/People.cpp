#include "People.h"
#include <algorithm>

CPEOPLE::CPEOPLE()
    : CEntity({cfg::PlayWidth * 0.5f, cfg::WindowHeight - cfg::Tile - 18.f}, {34.f, 42.f}, 0.f) {
}

void CPEOPLE::reset() {
    m_position = {cfg::PlayWidth * 0.5f, cfg::WindowHeight - cfg::Tile - 18.f};
    m_alive = true;
    m_blinkTimer = 0.f;
}

void CPEOPLE::moveByTile(Direction direction) {
    if (!m_alive) {
        return;
    }

    switch (direction) {
    case Direction::Up:
        m_position.y -= cfg::Tile;
        break;
    case Direction::Down:
        m_position.y += cfg::Tile;
        break;
    case Direction::Left:
        m_position.x -= cfg::Tile;
        break;
    case Direction::Right:
        m_position.x += cfg::Tile;
        break;
    case Direction::None:
        break;
    }

    m_position.x = std::clamp(m_position.x, 8.f, cfg::PlayWidth - m_size.x - 8.f);
    m_position.y = std::clamp(m_position.y, 8.f, cfg::WindowHeight - m_size.y - 8.f);
}

void CPEOPLE::kill() {
    m_alive = false;
    m_blinkTimer = 1.2f;
}

bool CPEOPLE::isAlive() const {
    return m_alive;
}

bool CPEOPLE::isFinish() const {
    return m_position.y <= 18.f;
}

bool CPEOPLE::isImpact(const CEntity& entity) const {
    return m_alive && getBounds().intersects(entity.getBounds());
}

void CPEOPLE::update(float dt) {
    if (!m_alive && m_blinkTimer > 0.f) {
        m_blinkTimer -= dt;
    }
}

void CPEOPLE::draw(sf::RenderWindow& window) const {
    if (!m_alive && static_cast<int>(m_blinkTimer * 12.f) % 2 == 0) {
        return;
    }

    sf::RectangleShape body(m_size);
    body.setPosition(m_position);
    body.setFillColor(m_alive ? sf::Color(255, 239, 112) : sf::Color(255, 255, 255, 110));
    body.setOutlineThickness(3.f);
    body.setOutlineColor(sf::Color(35, 32, 24));
    window.draw(body);

    sf::RectangleShape face({m_size.x * 0.55f, 8.f});
    face.setPosition(m_position.x + 8.f, m_position.y + 9.f);
    face.setFillColor(sf::Color(70, 50, 35));
    window.draw(face);
}
