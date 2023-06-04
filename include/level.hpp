/**
 * @file level.hpp
 * @author Rob Barton (robamesgam.es)
 * @brief A class for reading a text file to generate a game level.
 * A game level consists of various arrangements of bricks that need
 * to be destroyed.
 */

#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <raylib.h>

#include "brick.hpp"

class Level {

  public:

    std::vector<std::vector<int>> level_data;
    std::vector<Brick> bricks;
    const char *level_file;

    /**
     * @brief Construct a new Level object
     * @param level_file - text file representing a game level
     */
    Level(const char *level_file) : level_file(level_file) {}

    /**
     * @brief Generates a game level using the the level_data vector built from
     * a level file
     */
    void GenerateLevel();

    /**
     * @brief Renders a game level
     */
    void Draw();

    /**
     * @brief Checks to see if a level is complete
     * @return true - if complete
     * @return false - if not complete
     */
    bool IsLevelComplete();

    /**
     * @brief Get the Number Of  bricks remaining in the current active level
     * @return int - number of remaining bricks
     */
    int GetNumberOfBricksRemaining();
    void ResetLevel();

  private:

    /**
     * @brief Reads a level file and builds a 2D vector of level data that
     * will be used to generate a game level
     * @return std::vector<std::vector<int>>
     */
    std::vector<std::vector<int>> ReadLevelFromFile();
};

#endif
