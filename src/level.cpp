/**
 * @file level.cpp
 * @author Rob Barton (robamesgam.es)
 * @brief Implementation of level.hpp
 */

#include <sstream>
#include <fstream>

#include "level.hpp"

#undef RED
#undef ORANGE
#undef BROWN
#undef YELLOW
#undef GREEN
#undef BLUE

// clang-format off
#define RED (Color) { 201, 70, 70, 255 }   
#define ORANGE (Color) { 199, 108, 55, 255 }
#define BROWN (Color) { 182, 123, 44, 255 }   
#define YELLOW (Color) {163, 164, 37, 255 }   
#define GREEN (Color) { 70, 161, 70, 255 }   
#define BLUE (Color) { 64, 70, 201, 255 }
// clang-format on

void Level::GenerateLevel() {
    level_data.clear();
    bricks.clear();
    level_data = ReadLevelFromFile();
    int level_width = GetScreenWidth();
    int level_height = GetScreenHeight();
    int brick_num_y = level_data.size();
    int brick_num_x = level_data[0].size();
    float brick_width = level_width / (brick_num_x);
    float brick_height = (((level_height / 2) / brick_num_y)) / 2;
    int top_offset = 30;
    int side_offset = 4;

    for (int y = 0; y < brick_num_y; ++y) {
        for (int x = 0; x < brick_num_x; ++x) {
            if (level_data[y][x] == 1) {
                Brick brick(glm::vec2(brick_width * x + side_offset, brick_height * y + top_offset),
                            glm::vec2(brick_width, brick_height), RED, 1);
                bricks.push_back(brick);
            } else if (level_data[y][x] == 2) {
                Brick brick(glm::vec2(brick_width * x + side_offset, brick_height * y + top_offset),
                            glm::vec2(brick_width, brick_height), ORANGE, 1);
                bricks.push_back(brick);
            } else if (level_data[y][x] == 3) {
                Brick brick(glm::vec2(brick_width * x + side_offset, brick_height * y + top_offset),
                            glm::vec2(brick_width, brick_height), BROWN, 1);
                bricks.push_back(brick);
            } else if (level_data[y][x] == 4) {
                Brick brick(glm::vec2(brick_width * x + side_offset, brick_height * y + top_offset),
                            glm::vec2(brick_width, brick_height), YELLOW, 1);
                bricks.push_back(brick);
            } else if (level_data[y][x] == 5) {
                Brick brick(glm::vec2(brick_width * x + side_offset, brick_height * y + top_offset),
                            glm::vec2(brick_width, brick_height), GREEN, 1);
                bricks.push_back(brick);
            } else if (level_data[y][x] == 6) {
                Brick brick(glm::vec2(brick_width * x + side_offset, brick_height * y + top_offset),
                            glm::vec2(brick_width, brick_height), BLUE, 1);
                bricks.push_back(brick);
            }
        }
    }
}

std::vector<std::vector<int>> Level::ReadLevelFromFile() {
    std::string line;
    std::ifstream fstream(level_file);

    int brick_code;
    if (fstream) {
        while (std::getline(fstream, line)) {
            std::istringstream sstream(line);
            std::vector<int> row;
            while (sstream >> brick_code) {
                row.push_back(brick_code);
            }
            level_data.push_back(row);
        }
    }

    return level_data;
}

bool Level::IsLevelComplete() {
    for (Brick brick : bricks) {
        if (!brick.is_destroyed) {
            return false;
        }
    }
    return true;
}

void Level::Draw() {
    for (Brick &brick : this->bricks) {
        if (!brick.is_destroyed) {
            brick.Draw();
        }
    }
}

void Level::ResetLevel() {
    for (Brick brick : this->bricks) {
        if (brick.is_destroyed) {
            std::cout << "destroyed" << std::endl;
            brick.is_destroyed = false;
        }
    }
}

int Level::GetNumberOfBricksRemaining() {
    int total = 0;
    for (Brick &brick : this->bricks) {
        if (!brick.is_destroyed) {
            total++;
        }
    }

    return total;
}