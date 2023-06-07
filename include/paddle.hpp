/**
 * @file paddle.hpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Represents the paddle in a game of Brick Breaker. The paddles movement
 * is handled here.
 *
 */

#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <glm/glm.hpp>
#include <raylib.h>

class Paddle {

  public:

    float offset{50.0f};
    glm::vec2 pos{glm::vec2(GetScreenWidth() / 2, GetScreenHeight() - offset)};
    glm::vec2 STARTING_POSITION{pos};
    glm::vec2 size{glm::vec2(100, 10)};
    glm::vec2 DEFAULT_SIZE{size};
    float speed{10};
    float DEFAULT_SPEED = {speed};
    float velocity{100};
    float max_speed{20};
    Color color{RED};

    /**
     * @brief Moves the paddle left
     */
    void MoveLeft();

    /**
     * @brief Moves the paddle right
     */
    void MoveRight();

    /**
     * @brief Get the Rect object
     * @return Rectangle
     */
    Rectangle GetRect();

    /**
     * @brief Resets the paddle to its starting position
     */
    void Reset();

    /**
     * @brief Renders the paddle to the screen
     */
    void Draw();
};

#endif