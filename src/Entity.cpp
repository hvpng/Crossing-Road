#include "Entity.h"

CEntity::CEntity(sf::Vector2f position, sf::Vector2f size, float speed)
    : m_position(position), m_size(size), m_speed(speed) {
}

sf::FloatRect CEntity::getBounds() const {
    return {m_position, m_size};
}

sf::Vector2f CEntity::getPosition() const {
    return m_position;
}
