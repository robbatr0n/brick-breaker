/**
 * @file debug.hpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Draws useful debug information to the screen.
 *
 */

#include "brick_breaker.hpp"

namespace debug {

    void DrawGameStateData(GameState state, int lives, int current_level, int score,
                           int level_count);

}