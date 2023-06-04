/**
 * @file brick.cpp
 * @author Rob Barton (robamesgam.es)
 * @brief Implementation of brick,hpp
 */

#include <glm/glm.hpp>
#include <raylib.h>

#include "brick.hpp"

void Brick::Draw() {
    if (!is_destroyed) {
        DrawRectangle(pos.x, pos.y, size.x, size.y, color);
    }
}