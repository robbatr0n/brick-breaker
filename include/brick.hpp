/**
 * @file brick.hpp
 * @author Rob Barton (robamesgam.es)
 * @brief Class that defines a singular brick used to create a game level.
 * Bricks have lives that represent how many hits are requried to destroy them.
 */

#ifndef BRICK_HPP
#define BRICK_HPP

#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <raylib.h>

class Brick {

  public:

    glm::vec2 pos;
    glm::vec2 size;
    Color color;
    int lives;
    bool is_destroyed{false};

    /**
     * @brief Construct a new Brick object
     * @param pos - brick position
     * @param size - brick size
     * @param color - brick colour
     * @param lives - amount of times a brick must be hit before being destroyed
     */
    Brick(glm::vec2 pos, glm::vec2 size, Color color, int lives)
        : pos(pos), size(size), color(color), lives(lives) {}

    /**
     * @brief Renders a brick to the screen if they have not been destroyed
     */
    void Draw();
};

#endif