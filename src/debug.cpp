/**
 * @file debug.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Implementation file for debug.hpp
 *
 */

#include <raylib.h>

#include "debug.hpp"

void debug::DrawGameStateData(GameState state) {
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
}