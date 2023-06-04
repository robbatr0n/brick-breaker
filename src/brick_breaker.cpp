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
#include "debug.hpp"

void BrickBreaker::Init() {}

void BrickBreaker::Update() {}

void BrickBreaker::ProcessInput() {
    // Game main menu
    if (state == GAME_START) {
        if (IsKeyPressed(KEY_SPACE)) {
            state = PRE_GAME;
        }
    }

    // Game loaded but round not started
    else if (state == PRE_GAME) {
        if (IsKeyPressed(KEY_SPACE)) {
            state = GAME_ACTIVE;
        }
    }

    // Game in progress
    else if (state == GAME_ACTIVE) {

    }

    // Game over - all lives lost
    else if (state == GAME_OVER) {

    }

    // Game Complete - all levels finished
    else if (state == GAME_COMPLETE) {
    }
}

void BrickBreaker::Render() {
    BeginDrawing();
    ClearBackground(BLACK);
    debug::DrawGameStateData(state);
    EndDrawing();
}
