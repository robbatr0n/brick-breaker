/**
 * @file main.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Program entry point. Creates a window and if the window is
 * created successfully, the game is launched,
 *
 */

#include <iostream>

#include <glm/glm.hpp>
#include <raylib.h>

#include "game.hpp"

int main() {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const char *TITLE = "Brick Breaker";
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);

    if (IsWindowReady()) {
        game::Run();
    } else {
        std::cerr << "Error initialising window." << std::endl;
        return -1;
    }
    return 0;
}