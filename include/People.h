#pragma once

#include "Entity.h"
#include "Constants.h"

class CPEOPLE final : public CEntity {
public:
    CPEOPLE();
    void reset();
    void moveByTile(Direction direction);
    void kill();
    bool isAlive() const;
    bool isFinish() const;
    bool isImpact(const CEntity& entity) const;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) const override;

private:
    bool m_alive = true;
    float m_blinkTimer = 0.f;
};
