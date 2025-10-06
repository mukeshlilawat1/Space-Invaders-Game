#include "include/game.hpp"
#include <iostream>

Game::Game()
{
    // initialize game components if needed
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