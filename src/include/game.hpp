#pragma once
#include "spaceship.hpp"
#include "Obstacle.hpp"
#include "Alien.hpp"

class Game {
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();

    private:
    void DeleteInactiveLasers();
    std::vector<Obstacle>CreateObstacles();
    std::vector<Alien>CreateAlien();
    Spaceship spaceship;
    std::vector<Obstacle>obstacles;
    std::vector<Alien> aliens;

};
