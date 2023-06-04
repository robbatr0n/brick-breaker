/**
 * @file brick_breaker.hpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Primary game class. Responsible for initialising, updating and
 * rendering the game. The majority of the game logic happens here.
 *
 */

#ifndef BRICK_BREAKER_HPP
#define BRICK_BREAKER_HPP

#include "paddle.hpp"
#include "ball.hpp"
#include "level.hpp"
#include "powerup.hpp"

/**
 * @brief Contains all game state options
 *  GAME_START - The games main menu
 *  GAME_ACTIVE - A round of brick breaker is in progress
 *  PRE_GAME - Level has loaded but game has not started yet
 *  GAME_OVER - A player has lost all of their lives
 *  GAME_COMPLETE - A levels have been completed
 */
enum GameState {
    GAME_START,
    PRE_GAME,
    GAME_ACTIVE,
    GAME_OVER,
    GAME_COMPLETE
};

class BrickBreaker {

  public:

    GameState state{GAME_START};
    Paddle paddle;
    Ball ball;
    int current_level;
    int level_count;
    std::vector<Level> levels;
    int score;
    int lives;

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

    /**
     * @brief Loads all game levels inside the levels folder into the levels vector
     * ready to be drawn to the screen
     */
    void LoadLevels();

    /**
     * @brief Watches for and handles any collisions between game objects
     */
    void HandleCollisions();

    /**
     * @brief Resets the round after a life has been lost. Responsible for:
     */
    void ResetRound();

    /**
     * @brief Resets the game after all lives has been lost. Responsible for:
     */
    void ResetGame();
};

#endif