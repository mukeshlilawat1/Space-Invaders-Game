#include <raylib.h>
// #include "include/spaceship.hpp"
#include "include/game.hpp"
#include "include/laser.hpp"

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

    // Spaceship spaceship;
    Game game;
    Laser laser = Laser({100, 100}, 7);

    // main game loop
    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        laser.update();

        BeginDrawing();

        // clear background
        ClearBackground(grey);

        // draw spaceship
        // spaceship.draw();
        game.Draw();
        laser.Draw();

        EndDrawing();
    }

    // close window and clean up
    CloseWindow();
}