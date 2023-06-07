/**
 * @file brick_breaker.cpp
 * @author Rob Barton (robmakesgam.es)
 * @brief Implements brick_breaker.hpp
 *
 */

#include <iostream>
#include <filesystem>
#include <tuple>
#include <cmath>
#include <cstdlib>

#include <glm/glm.hpp>
#include <raylib.h>

#include "brick_breaker.hpp"
#include "game.hpp"
#include "check_collisions.hpp"
#include "gui.hpp"
#include "debug.hpp"

bool ShouldSpawn(unsigned int chance);
bool ShouldSpawn(unsigned int chance) {
    unsigned int random = rand() % chance;
    return random == 0;
}

void BrickBreaker::Init() {
    current_level = 0;
    score = 0;
    lives = 3;
    LoadLevels();
}

void BrickBreaker::Update() {

    if (!ball.is_stuck && state == GAME_ACTIVE) {
        ball.Move();
    } else {
        ball.StickBallToPaddle(paddle.pos, paddle.size);
    }

    if (ball.pos.y > GetScreenHeight()) {
        lives--;
        score = score / 2;
        ResetRound();
    }

    if (lives == 0) {
        state = GAME_OVER;
    }

    if (state == GAME_ACTIVE) {
        if (levels[current_level].IsLevelComplete()) {
            if ((current_level + 1) == level_count) {
                state = GAME_COMPLETE;
            } else {
                current_level++;
                ResetRound();
            }
        }
    }

    for (Powerup &powerup : powerups) {
        powerup.Move();
    }

    HandleCollisions();
}

void BrickBreaker::ProcessInput() {
    // Game main menu
    if (state == GAME_START) {
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            gui::MoveUpMainMenu();
        }
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
            gui::MoveDownMainMenu();
        }
        if (gui::GetCurrentMainMenuOption() == 1 && IsKeyPressed(KEY_SPACE)) {
            state = PRE_GAME;
        }

        if (gui::GetCurrentMainMenuOption() == 3 && IsKeyPressed(KEY_SPACE)) {
            CloseWindow();
        }
    }

    // Game loaded but round not started
    else if (state == PRE_GAME) {
        if (IsKeyPressed(KEY_SPACE)) {
            state = GAME_ACTIVE;
        }
    }

    // Game in progress
    else if (state == GAME_ACTIVE) {
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
            paddle.MoveLeft();
        }
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
            paddle.MoveRight();
        }
        if (IsKeyPressed(KEY_SPACE)) {
            ball.ReleaseBall();
        }
    }

    // Game over - all lives lost
    else if (state == GAME_OVER) {
        if (IsKeyPressed(KEY_SPACE)) {
            state = GAME_START;
            ResetGame();
        }
    }

    // Game Complete - all levels finished
    else if (state == GAME_COMPLETE) {
        if (IsKeyPressed(KEY_SPACE)) {
            state = GAME_START;
            ResetGame();
        }
    }
}

void BrickBreaker::Render() {
    BeginDrawing();
    ClearBackground(BLACK);

    // Game main menu
    if (state == GAME_START) {
        gui::DrawMainMenu();
    }

    if (state == PRE_GAME) {
        gui::DrawPreGameUI();
    }

    // Game in progress or Game loaded but round not started
    if (state == GAME_ACTIVE || state == PRE_GAME) {
        paddle.Draw();
        ball.Draw();
        levels[current_level].Draw();
        for (Powerup &powerup : powerups) {
            powerup.Draw();
        }
        gui::DrawInGameUI(lives, score, current_level, level_count);
    }

    // Game over - all lives lost
    else if (state == GAME_OVER) {
        gui::DrawGameOverScreen();
    }

    // Game Complete - all levels finished
    else if (state == GAME_COMPLETE) {
        gui::DrawGameCompleteScreen(score);
    }

    EndDrawing();
}

void BrickBreaker::LoadLevels() {
    level_count = std::distance(std::filesystem::recursive_directory_iterator{"../levels/"}, {});
    levels.clear();
    for (int i = 0; i < level_count; i++) {
        std::string file_string = "../levels/level" + std::to_string(i + 1) + ".lvl";
        Level level(file_string.c_str());
        level.GenerateLevel();
        levels.push_back(level);
    }
}

void BrickBreaker::HandleCollisions() {

    // ball - paddle collisions
    if (check_collisions::CheckPaddleBallCollisions(paddle, ball)) {
        ball.velocity.y = -ball.velocity.y;
        if (ball.pos.x < paddle.pos.x) {
            if (ball.velocity.x > 0) {
                ball.velocity.x = -ball.velocity.x;
            }
        } else if (ball.pos.x > paddle.pos.x) {
            ball.velocity.x = std::abs(ball.velocity.x);
        }
    }

    // ball - brick collision
    for (Brick &brick : levels[current_level].bricks) {

        if (!brick.is_destroyed) {

            Collision collision = check_collisions::CheckBallBrickCollisions(ball, brick);

            if (std::get<0>(collision)) {
                if (ShouldSpawn(15)) {
                    Powerup powerup;
                    powerup.SpawnPowerup(brick.pos);
                    powerups.push_back(powerup);
                    std::cout << "power up added" << std::endl;
                }
                if (brick.lives > 1) {
                    brick.lives--;
                    score += 10;
                } else {
                    brick.is_destroyed = true;
                    score += 50;
                }
                Direction dir = std::get<1>(collision);
                glm::vec2 diff_vector = std::get<2>(collision);

                if (dir == LEFT || dir == RIGHT) {
                    ball.velocity.x = -ball.velocity.x;
                    float penetration = ball.radius - std::abs(diff_vector.x);
                    if (dir == LEFT)
                        ball.pos.x += penetration;
                    else
                        ball.pos.x -= penetration;
                } else {
                    ball.velocity.y = -ball.velocity.y;
                    float penetration = ball.radius - std::abs(diff_vector.y);
                    if (dir == TOP)
                        ball.pos.y -= penetration;
                    else
                        ball.pos.y += penetration;
                }
            }
        }
    }

    if (powerups.size() > 0) {
        for (int i = 0; i < powerups.size(); i++) {
            if (check_collisions::CheckPaddlePowerupCollisions(paddle, powerups[i])) {
                ActivatePowerup(powerups[i].GetPowerupType());
                powerups[i].hit = true;
                powerups.erase(powerups.begin() + i);
            }
        }
    }
}

void BrickBreaker::ActivatePowerup(PowerupType p) {
    if (p == SUPER_SPEED) {
        paddle.speed = paddle.max_speed;
    } else if (p == BIG_PADDLE) {
        paddle.size = glm::vec2(paddle.DEFAULT_SIZE.x * 2, paddle.size.y);
    }
}

void BrickBreaker::DisablePowerups() {
    powerups.clear();
}

void BrickBreaker::ResetRound() {
    ball.Reset();
    paddle.Reset();
    DisablePowerups();
}

void BrickBreaker::ResetGame() {
    ball.Reset();
    paddle.Reset();
    DisablePowerups();
    Init();
}
