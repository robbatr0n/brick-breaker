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
    MULTI_BALL,
    BIG_PADDLE
};

class Powerup {

  public:

    glm::vec2 pos;
    Color color;
    PowerupType active_powerup;
    float duration;
    glm::vec2 velocity{0, 20.0f};
    bool is_active;

    Powerup(glm::vec2 pos, Color color) : pos(pos), color(color) {}
    void ActivatePowerup();
    PowerupType ChoosePowerup();
    void Draw();
    void Move();
};

#endif