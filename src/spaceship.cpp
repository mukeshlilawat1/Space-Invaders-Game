#include "include/spaceship.hpp"

Spaceship::Spaceship()
{
    image = LoadTexture("Graphics/spaceShip1.png");
    position.x = (GetScreenWidth() - image.width) / 2;
    position.y = GetScreenHeight() - image.height;
    laserFireTime = 0.0;
}

Spaceship::~Spaceship()
{
    UnloadTexture(image);
}

void Spaceship::draw()
{
    DrawTextureV(image, position, WHITE);
}

void Spaceship::MoveLeft()
{
    position.x -= 7;
    if (position.x < 0)
    {
        position.x = 0;
    }
}

void Spaceship::MoveRight()
{
    position.x += 7;
    if (position.x > GetScreenHeight() - image.width)
    {
        position.x = GetScreenHeight() - image.width;
    }
}

void Spaceship::FireLaser()
{
    if (GetTime() - laserFireTime >= 0.35)
    {

        laser.push_back(Laser({position.x + image.width / 2 - 2, position.y}, -6));
        laserFireTime = GetTime();
    }
}