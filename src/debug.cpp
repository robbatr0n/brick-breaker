/**
 * @file debug.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Implementation file for debug.hpp
 *
 */

#include <raylib.h>

#include "debug.hpp"

void debug::DrawGameStateData(GameState state, int lives, int current_level, int score,
                              int level_count) {
    const char *state_text;
    if (state == 0) {
        state_text = "GAME_START";
    }
    if (state == 1) {
        state_text = "PRE_GAME";
    }
    if (state == 2) {
        state_text = "GAME_ACTIVE";
    }
    if (state == 3) {
        state_text = "GAME_OVER";
    }
    if (state == 4) {
        state_text = "GAME_COMPLETE";
    }

    DrawText(state_text, 10, 300, 16, WHITE);
    DrawText(TextFormat("lives: %i", lives), 10, 320, 16, WHITE);
    DrawText(TextFormat("current level: %i", current_level), 10, 340, 16, WHITE);
    DrawText(TextFormat("score: %i", score), 10, 360, 16, WHITE);
    DrawText(TextFormat("total levels: %i", level_count), 10, 380, 16, WHITE);
}

void debug::DrawPaddleInfo(int paddle_speed) {
    DrawText(TextFormat("Speed: %i", paddle_speed), GetScreenWidth() - 100, 300, 16, WHITE);
}