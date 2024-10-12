#include <iostream>
#include <raylib.h>
#include "game.h"

// Main game FILE

#define DARKBLUE \
    (Color) { 0, 82, 172, 255 }
#define PURPLE \
    (Color) { 200, 122, 255, 255 }
#define VIOLET \
    (Color) { 135, 60, 190, 255 }
#define DARKPURPLE \
    (Color) { 112, 31, 126, 255 }
#define LIME \
    (Color) { 0, 158, 47, 255 }

int main()
{

    InitWindow(300, 600, "!!---TITRIS---!!");

    Game game;
    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        game.draw();
        EndDrawing();
    }
    CloseWindow();
}