/**
 * @file check_collisions.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Implementation of check_collisions.hpp
 *
 */

#include <tuple>

#include "check_collisions.hpp"

bool check_collisions::CheckPaddleBallCollisions(Paddle paddle, Ball ball) {
    if (CheckCollisionRecs(paddle.GetRect(), ball.GetRect())) {
        return true;
    } else {
        return false;
    }
}

bool check_collisions::CheckPaddlePowerupCollisions(Paddle paddle, Powerup powerup) {
    if (CheckCollisionRecs(paddle.GetRect(), powerup.GetRect())) {
        return true;
    } else {
        return false;
    }
}

Collision check_collisions::CheckBallBrickCollisions(Ball ball, Brick brick) {
    glm::vec2 center(ball.pos + ball.radius);   // Get center point of the ball
    // calculate AABB info (center, half-extents)
    glm::vec2 aabb_half_extents(brick.size.x / 2.0f, brick.size.y / 2.0f);
    glm::vec2 aabb_center(brick.pos.x + aabb_half_extents.x, brick.pos.y + aabb_half_extents.y);
    // get difference vector between both centers
    glm::vec2 difference = center - aabb_center;
    glm::vec2 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);
    // now that we know the clamped values, add this to AABB_center and we get the value of box
    // closest to circle
    glm::vec2 closest = aabb_center + clamped;
    // now retrieve vector between center circle and closest point AABB and check if length < radius
    difference = closest - center;

    if (glm::length(difference) <
        ball.radius)   // not <= since in that case a collision also occurs when
                       // object one exactly touches object two, which they are at
                       // the end of each collision resolution stage.
        return std::make_tuple(true, GetVectorDirection(difference), difference);
    else
        return std::make_tuple(false, TOP, glm::vec2(0.0f, 0.0f));
}

Direction check_collisions::GetVectorDirection(glm::vec2 v) {
    glm::vec2 compass[] = {
        glm::vec2(0.0f, 1.0f),    // up
        glm::vec2(1.0f, 0.0f),    // right
        glm::vec2(0.0f, -1.0f),   // down
        glm::vec2(-1.0f, 0.0f)    // left
    };
    float max = 0.0f;
    unsigned int best_match = -1;
    for (unsigned int i = 0; i < 4; i++) {
        float dot_product = glm::dot(glm::normalize(v), compass[i]);
        if (dot_product > max) {
            max = dot_product;
            best_match = i;
        }
    }
    return (Direction)best_match;
}