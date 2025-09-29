#pragma once
#include <raylib.h>

class Spaceship
{
public:
    Spaceship();
    ~Spaceship();
    void draw();
    void MoveLeft();
    void MoveRight();
    void FireLaser();

private:
    Texture2D image;
    Vector2 position;
};