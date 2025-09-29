#include <raylib.h>

int main()
{
    // define colors
    Color grey = {29, 29, 27, 255};

    // window dimensions
    int windowWidth = 800;
    int windowHeight = 600;

    // initialize window and set fps
    InitWindow(windowWidth, windowHeight, "C++ Space Invaders");
    SetTargetFPS(60);

    // main game loop
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    // close window and clean up
    CloseWindow();
}