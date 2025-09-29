#include "include/game.hpp"

Game::Game() {
    // initialize game components if needed
}

Game::~Game() {
    // clean up resources if needed
}

void Game::Draw() {
    spaceship.draw();
}

void Game::HandleInput() {
    if (IsKeyDown(KEY_LEFT))
    {
        spaceship.MoveLeft();
    } else if (IsKeyDown(KEY_RIGHT))
    {
        spaceship.MoveRight();
    }

}