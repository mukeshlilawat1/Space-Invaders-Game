#include <raylib.h>
// #include "include/spaceship.hpp"
#include "include/game.hpp"
// #include "include/laser.hpp"
// #include "include/obstacle.hpp"


int main()
{
    // define colors
    Color grey = {25, 30, 35, 255};

    // window dimensions
    int windowWidth = 750;
    int windowHeight = 700;

    // initialize window and set fps
    InitWindow(windowWidth, windowHeight, "C++ Space Invaders");
    SetTargetFPS(60);

    // Spaceship spaceship;
    Game game;
    // Laser laser = Laser({100, 100}, 7);
    // Obstacle obstacle = Obstacle({100, 100});

    // main game loop
    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        // laser.update();
        game.Update();

        BeginDrawing();

        // clear background
        ClearBackground(grey);

        // draw spaceship
        // spaceship.draw();
        game.Draw();
        // obstacle.Draw();
        // laser.Draw();

        EndDrawing();
    }

    // close window and clean up
    CloseWindow();
}