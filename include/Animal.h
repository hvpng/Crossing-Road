#pragma once

#include "Entity.h"
#include "Constants.h"

class CANIMAL : public CEntity {
public:
    CANIMAL(sf::Vector2f position, sf::Vector2f size, float speed, int lane, int direction, sf::Color color);
    void update(float dt) override;
    void draw(sf::RenderWindow& window) const override;

protected:
    int m_lane;
    int m_direction;
    sf::Color m_color;
};

class CDINAUSOR final : public CANIMAL {
public:
    CDINAUSOR(sf::Vector2f position, int lane, int direction);
};

class CBIRD final : public CANIMAL {
public:
    CBIRD(sf::Vector2f position, int lane, int direction);
};
