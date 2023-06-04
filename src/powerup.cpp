/**
 * @file powerup.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Implementation for powerup.hpp
 *
 */

#include "powerup.hpp"

void Powerup::ActivatePowerup() {
    is_active = true;
    active_powerup = SUPER_SPEED;
}

PowerupType Powerup::ChoosePowerup() {}

void Powerup::Draw() {
    if (is_active) {
        DrawRectangle(pos.x, pos.y, 20, 20, color);
    }
}

void Powerup::Move() {
    pos += velocity * GetFrameTime();
}