/**
 * @file paddle.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Implementation of paddle.hpp
 *
 */

#include "paddle.hpp"

void Paddle::MoveLeft() {
    if (pos.x < 0) {
        pos.x = 0;
    } else {
        pos.x += speed * (-velocity) * GetFrameTime();
    }
}

void Paddle::MoveRight() {
    if (pos.x > GetScreenWidth()) {
        pos.x = GetScreenWidth();
    } else {
        pos.x += speed * velocity * GetFrameTime();
    }
}

Rectangle Paddle::GetRect() {
    return Rectangle{pos.x - size.x / 2, pos.y - size.y / 2, size.x, size.y};
}

void Paddle::Reset() {
    pos = STARTING_POSITION;
    speed = DEFAULT_SPEED;
    size = DEFAULT_SIZE;
}

void Paddle::Draw() {
    DrawRectangleRec(GetRect(), color);
}