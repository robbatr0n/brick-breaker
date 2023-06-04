/**
 * @file ball.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Implementation for ball.hpp
 *
 */

#include "ball.hpp"

Ball::Ball() {
    radius = {(float)sqrt(size.x / 2) * (float)sqrt(size.x / 2)};
}

void Ball::StickBallToPaddle(glm::vec2 paddle_pos, glm::vec2 paddle_size) {
    pos.x = paddle_pos.x;
    pos.y = paddle_pos.y - paddle_size.y;
}

void Ball::Move() {
    pos += velocity * GetFrameTime();
    // X left collision
    if (pos.x <= 0.0f) {
        velocity.x = -velocity.x;
        pos.x = 0.0f;
    }
    // X right collision
    else if (pos.x + size.x >= GetScreenWidth()) {
        velocity.x = -velocity.x;
        pos.x = GetScreenWidth() - size.x;
    }
    // top collision
    if (pos.y <= 0.0f) {
        velocity.y = -velocity.y;
        pos.y = 0.0f;
    }
}

Rectangle Ball::GetRect() {
    return Rectangle{pos.x - size.x / 2, pos.y - size.y / 2, size.x, size.y};
}

void Ball::ReleaseBall() {
    is_stuck = false;
}

void Ball::Reset() {
    is_stuck = true;
    velocity = DEFAULT_VELOCITY;
}

void Ball::Draw() {
    DrawRectangleRec(GetRect(), color);
}