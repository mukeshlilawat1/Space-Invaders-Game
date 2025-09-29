#include <raylib.h>
#include "include/spaceship.hpp"

int main()
{
    // define colors
    Color grey = {29, 29, 27, 255};

    // window dimensions
    int windowWidth = 750;
    int windowHeight = 700;

    // initialize window and set fps
    InitWindow(windowWidth, windowHeight, "C++ Space Invaders");
    SetTargetFPS(60);

    Spaceship spaceship;

    // main game loop
    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // clear background
        ClearBackground(grey);

        // draw spaceship
        spaceship.draw();

        EndDrawing();
    }

    // close window and clean up
    CloseWindow();
}