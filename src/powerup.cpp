/**
 * @file powerup.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Implementation for powerup.hpp
 *
 */
#include <random>

#include "powerup.hpp"

void Powerup::SpawnPowerup(glm::vec2 pos) {

    this->pos = pos;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 1);   // define the range

    if (distr(gen) == 0) {
        type = SUPER_SPEED;
        color = RED;
    } else if (distr(gen) == 1) {
        type = BIG_PADDLE;
        color = GREEN;
    }
}

Rectangle Powerup::GetRect() {
    return Rectangle{pos.x - size.x / 2, pos.y - size.y / 2, size.x, size.y};
}

PowerupType Powerup::GetPowerupType() {
    return type;
}

void Powerup::Move() {
    pos.y += velocity.y * GetFrameTime();
}

void Powerup::Draw() {
    if (!hit) {
        DrawRectangle(pos.x, pos.y, 20, 20, color);
    }
}