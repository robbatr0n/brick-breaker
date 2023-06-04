/**
 * @file brick_breaker.hpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Primary game class. Responsible for initialising, updating and
 * rendering the game. The majority of the game logic happens here.
 *
 */

#ifndef BRICK_BREAKER_HPP
#define BRICK_BREAKER_HPP

/**
 * @brief Contains all game state options
 *  GAME_START - The games main menu
 *  GAME_ACTIVE - A round of brick breaker is in progress
 *  LEVEL_COMPLETE - A player has completed a level
 *  GAME_OVER - A player has lost all of their lives
 *  GAME_COMPLETE - A levels have been completed
 */
enum GameState {
    GAME_START,
    GAME_ACTIVE,
    LEVEL_COMPLETE,
    GAME_OVER,
    GAME_COMPLETE
};

class BrickBreaker {

  public:

    GameState state;

    /**
     * @brief Initialises the game. Responsible for:
     */
    void Init();

    /**
     * @brief Updates the game. Responsible for:
     */
    void Update();

    /**
     * @brief Handles user input. Responsible for:
     */
    void ProcessInput();

    /**
     * @brief Renders the game to the screen. What is
     * rendered depends on the game state
     */
    void Render();
};

#endif