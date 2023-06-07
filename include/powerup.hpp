/**
 * @file powerup.hpp
 * @author Rob Barton (robmakesgam.es)
 * @brief
 *
 */

#ifndef POWERUP_HPP
#define POWERUP_HPP

#include <glm/glm.hpp>
#include <raylib.h>

enum PowerupType {
    SUPER_SPEED,
    BIG_PADDLE
};

class Powerup {

  public:

    glm::vec2 pos;
    glm::vec2 size{50, 50};
    glm::vec2 velocity{0, 100};
    Color color{BLUE};
    PowerupType type;
    bool hit{false};

    /**
     * @brief Spawns a new random powerup
     * @param pos
     */
    void SpawnPowerup(glm::vec2 pos);

    /**
     * @brief Get the Rect object
     * @return Rectangle
     */
    Rectangle GetRect();

    /**
     * @brief Get the type of powerup
     * @return PowerupType
     */
    PowerupType GetPowerupType();

    /**
     * @brief Moves powerups down the screen to be collected by the player
     */
    void Move();

    /**
     * @brief Draws the powerup to the screen
     */
    void Draw();
};

#endif