/**
 * @file game.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Declares generic game methods responsible for the running
 * and stopping of the game.
 */

#ifndef GAME_HPP
#define GAME_HPP

namespace game {

    /**
     * @brief Creates a game object and runs it in the render the loop.
     * Providing calls to the Update, Render and ProcessInput methods.
     */
    void Run();

    /**
     * @brief Deallocates and terminates resources once the game has finished
     * running.
     */
    void CleanUp();
}

#endif