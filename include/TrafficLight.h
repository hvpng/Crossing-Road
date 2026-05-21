#pragma once

#include "Constants.h"
#include <SFML/Graphics.hpp>

class CTRAFFICLIGHT {
public:
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
    bool isRed() const;
    LightState getState() const;

private:
    LightState m_state = LightState::Green;
    float m_timer = 0.f;
};
