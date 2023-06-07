/**
 * @file game.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Implementation of game.hpp
 */

#include <iostream>

#include <glm/glm.hpp>
#include <raylib.h>

#include "game.hpp"
#include "brick_breaker.hpp"

void game::Run() {

    BrickBreaker brick_breaker;
    brick_breaker.Init();

    // game loop
    while (!WindowShouldClose()) {
        brick_breaker.ProcessInput();
        brick_breaker.Update();
        brick_breaker.Render();
    }

    CleanUp();
}

void game::CleanUp() {
    CloseWindow();
}