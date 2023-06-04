/**
 * @file brick_breaker.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Implements brick_breaker.hpp
 *
 */

#include <iostream>
#include <filesystem>
#include <tuple>
#include <cmath>
#include <cstdlib>

#include <glm/glm.hpp>
#include <raylib.h>

#include "brick_breaker.hpp"
#include "game.hpp"

void BrickBreaker::Init() {
    state = GAME_START;
}

void BrickBreaker::Update() {}

void BrickBreaker::ProcessInput() {}

void BrickBreaker::Render() {}
