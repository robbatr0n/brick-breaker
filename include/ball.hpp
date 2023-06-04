/**
 * @file ball.hpp
 * @author Rob Barton (robmakesgam.es)
 * @brief A class that represents a ball in the game of brick breaker.
 *
 */

#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <raylib.h>

class Ball {

  public:

    glm::vec2 pos;
    glm::vec2 size{10, 10};
    glm::vec2 velocity{100, -300};
    glm::vec2 DEFAULT_VELOCITY{velocity};
    Color color{BLUE};
    bool is_stuck{true};
    float radius;

    /**
     * @brief Construct a new Ball object
     */
    Ball();

    /**
     * @brief Moves the ball to the center of the padle
     * @param paddle_pos
     * @param paddle_size
     */
    void StickBallToPaddle(glm::vec2 paddle_pos, glm::vec2 paddle_size);

    /**
     * @brief Moves the ball
     */
    void Move();

    /**
     * @brief Get the Rect object
     * @return Rectangle
     */
    Rectangle GetRect();

    /**
     * @brief Unsticks the ball from the paddle
     */
    void ReleaseBall();

    /**
     * @brief Resets the balls position and velocity
     */
    void Reset();

    /**
     * @brief Renders the ball to the screen
     */
    void Draw();
};

#endif