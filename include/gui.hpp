/**
 * @file gui.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Functions for creating the game UI.
 *
 */

#ifndef GUI_HPP
#define GUI_HPP

#include "brick_breaker.hpp"

namespace gui {

    static int menu_option = 1;

    /**
     * @brief Draws the games main menu
     * @param menu_option  - currently highlighted menu option
     */
    void DrawMainMenu();

    /**
     * @brief Moves up the main menu
     */
    void MoveUpMainMenu();

    /**
     * @brief Moves down the main menu
     */
    void MoveDownMainMenu();

    /**
     * @brief Get the Current Main Menu Option
     * @return int - main menu option
     */
    int GetCurrentMainMenuOption();

    /**
     * @brief Draws the Pre Game UI
     */
    void DrawPreGameUI();

    /**
     * @brief Draws the in-game UI.
     * @param lives - player lives
     * @param score  - player score
     * @param current_level - current level being played
     * @param total_levels  - total levels in the game
     */
    void DrawInGameUI(int lives, int score, int current_level, int total_levels);

    /**
     * @brief Draws the current level at the start of each level. Text stops
     * being drawn once the game starts
     * @param level_text - current level
     */
    void DrawLevelText(int level_text);

    /**
     * @brief Draws the game over screen
     */
    void DrawGameOverScreen();

    /**
     * @brief Draws the game complete screen
     */
    void DrawGameCompleteScreen(int score);

};

#endif