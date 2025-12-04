#include "include/game.hpp"
// #include "include/obstacle.hpp"

#include <iostream>

Game::Game()
{
    // initialize game components if needed
    obstacles = CreateObstacles();
    aliens = CreateAlien();
}

Game::~Game()
{
    // clean up resources if needed
    Alien::UnloadImage();
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

    for(auto& alien : aliens) {
        alien.Draw();
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

std::vector<Alien> Game::CreateAlien() {
    std::vector<Alien>aliens;
    for(int row = 0; row < 5; row++) {
        for(int column = 0; column < 11; column++) {

            int alienType;
            if(row == 0) {
                alienType = 3;
            } else if ( row == 1 || row == 2) {
                alienType = 2;
            } else {
                alienType = 1;
            }

            float x = 75 + column * 55;
            float y = 110 + row * 55;
            aliens.push_back(Alien(alienType, {x, y}));
        }
    }
    return aliens;
}