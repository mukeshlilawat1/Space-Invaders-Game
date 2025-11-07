#include "include/game.hpp"
#include "include/obstacle.hpp"
#include <iostream>

Game::Game()
{
    // initialize game components if needed
    obstacles = CreateObstacles();
}

Game::~Game()
{
    // clean up resources if needed
}

void Game::Update()
{
    for (auto &lasers : spaceship.laser)
    {
        lasers.update();
    }
    DeleteInactiveLasers();
    // std::cout << "vector size : " << spaceship.laser.size() << std::endl;
}

void Game::Draw()
{
    spaceship.draw();

    for (auto &lasers : spaceship.laser)
    {
        lasers.Draw();
    }

    for(auto& obstacle: obstacles) {
        obstacle.Draw();
    }
}

void Game::HandleInput()
{
    if (IsKeyDown(KEY_LEFT))
    {
        spaceship.MoveLeft();
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
        spaceship.MoveRight();
    }
    else if (IsKeyDown(KEY_SPACE))
    {
        spaceship.FireLaser();
    }
}

void Game::DeleteInactiveLasers()
{
    for (auto it = spaceship.laser.begin(); it != spaceship.laser.end();)
    {
        if (!it->active)
        {
            it = spaceship.laser.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

std::vector<Obstacle> Game::CreateObstacles() {
    int obstacleWidth = Obstacle::grid[0].size() * 3;
    float gap = (GetScreenWidth() -(4 * obstacleWidth))/5;

    for(int i = 0; i < 4; i++) {
        float offsetX = (i + 1) * gap + i * obstacleWidth;
        obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 100)}));
    }
    return obstacles;
}