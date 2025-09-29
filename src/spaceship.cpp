#include "include/spaceship.hpp"

Spaceship::Spaceship()
{
    image = LoadTexture("Graphics/spaceship.png");
    position.x = 100;
    position.y = 100;
}

Spaceship::~Spaceship()
{
    UnloadTexture(image);
}

void Spaceship::draw()
{
    DrawTextureV(image, position, WHITE);
}