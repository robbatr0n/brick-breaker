/**
 * @file check_collisions.hpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Contains functions use to check for collisions between game objects.
 *
 */

#ifndef CHECK_COLLISIONS_HPP
#define CHECK_COLLISIONS_HPP

#include <raylib.h>

#include "paddle.hpp"
#include "ball.hpp"
#include "brick.hpp"

enum Direction {
    TOP,
    RIGHT,
    DOWN,
    LEFT
};

/**
 * @brief Custom type that indicates if a collision took place, the
 * direction of the collision and the point of the collision
 */
typedef std::tuple<bool, Direction, glm::vec2> Collision;

namespace check_collisions {

    /**
     * @brief Checks for a collision between the paddle and the ball
     * @param paddle
     * @param ball
     * @return true - if a collision happens
     * @return false - if a collision does not happen
     */
    bool CheckPaddleBallCollisions(Paddle paddle, Ball ball);

    /**
     * @brief Checks for a collision between the ball and a brick
     * @param ball
     * @param brick
     * @return Collision - contains if a collision happened, the side of
     * the brick where the collision happened and the point of collision
     */
    Collision CheckBallBrickCollisions(Ball ball, Brick brick);

    /**
     * @brief Get the Vector Direction object of where a collision happened
     * @param v
     * @return Direction
     */
    Direction GetVectorDirection(glm::vec2 v);
}

#endif