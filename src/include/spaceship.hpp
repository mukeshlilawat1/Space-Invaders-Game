#pragma once
#include <raylib.h>
#include "laser.hpp"
#include <vector>

class Spaceship
{
public:
    Spaceship();
    ~Spaceship();
    void draw();
    void MoveLeft();
    void MoveRight();
    void FireLaser();
    std::vector<Laser> laser;

private:
    Texture2D image;
    Vector2 position;
    double laserFireTime;
};