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
#include "gui.hpp"
#include "debug.hpp"

void BrickBreaker::Init() {}

void BrickBreaker::Update() {
    if (!ball.is_stuck) {
        ball.Move();
    } else {
        ball.StickBallToPaddle(paddle.pos, paddle.size);
    }
}

void BrickBreaker::ProcessInput() {
    // Game main menu
    if (state == GAME_START) {
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            gui::MoveUpMainMenu();
        }
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
            gui::MoveDownMainMenu();
        }
        if (gui::GetCurrentMainMenuOption() == 1 && IsKeyPressed(KEY_SPACE)) {
            state = PRE_GAME;
        }

        if (gui::GetCurrentMainMenuOption() == 3 && IsKeyPressed(KEY_SPACE)) {
            CloseWindow();
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
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
            paddle.MoveLeft();
        }
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
            paddle.MoveRight();
        }
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

    // Game main menu
    if (state == GAME_START) {
        gui::DrawMainMenu();
    }

    // Game in progress or Game loaded but round not started
    else if (state == GAME_ACTIVE || state == PRE_GAME) {
        paddle.Draw();
        ball.Draw();
    }

    // Game over - all lives lost
    else if (state == GAME_OVER) {

    }

    // Game Complete - all levels finished
    else if (state == GAME_COMPLETE) {
    }

    EndDrawing();
}
