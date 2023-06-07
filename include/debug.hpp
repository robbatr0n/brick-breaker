/**
 * @file debug.hpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Draws useful debug information to the screen.
 *
 */

#include "brick_breaker.hpp"

namespace debug {

    /**
     * @brief Draws various information regarding the state of the game
     * @param state
     * @param lives
     * @param current_level
     * @param score
     * @param level_count
     */
    void DrawGameStateData(GameState state, int lives, int current_level, int score,
                           int level_count);

    /**
     * @brief Drwas relevant information about the paddle
     * @param paddle_speed
     */
    void DrawPaddleInfo(int paddle_speed);

}