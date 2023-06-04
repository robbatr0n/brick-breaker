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
     * @brief
     */
    void MoveUpMainMenu();

    /**
     * @brief
     */
    void MoveDownMainMenu();

    /**
     * @brief Get the Current Main Menu Option object
     * @return int
     */
    int GetCurrentMainMenuOption();

    /**
     * @brief
     *
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
     * @brief
     */
    void DrawGameOverScreen();

    /**
     * @brief
     */
    void DrawGameCompleteScreen(int score);

};

#endif