#pragma once

#include "Entity.h"
#include "Constants.h"

class CVEHICLE : public CEntity {
public:
    CVEHICLE(sf::Vector2f position, sf::Vector2f size, float speed, int lane, int direction, sf::Color color);
    void setStopped(bool stopped);
    void update(float dt) override;
    void draw(sf::RenderWindow& window) const override;

protected:
    int m_lane;
    int m_direction;
    bool m_stoppedByRedLight = false;
    sf::Color m_color;
};

class CTRUCK final : public CVEHICLE {
public:
    CTRUCK(sf::Vector2f position, int lane, int direction);
};

class CCAR final : public CVEHICLE {
public:
    CCAR(sf::Vector2f position, int lane, int direction);
};
