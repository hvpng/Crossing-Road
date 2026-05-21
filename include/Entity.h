#pragma once

#include <SFML/Graphics.hpp>

class CEntity {
public:
    CEntity(sf::Vector2f position, sf::Vector2f size, float speed);
    virtual ~CEntity() = default;

    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;
    sf::FloatRect getBounds() const;
    sf::Vector2f getPosition() const;

protected:
    sf::Vector2f m_position;
    sf::Vector2f m_size;
    float m_speed;
};
