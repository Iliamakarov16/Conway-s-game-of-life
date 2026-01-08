#include "include/raylib.h"
#include "Simulation.hpp"

int main() 
{
    constexpr int SCREEN_WIDTH = 750;
    constexpr int SCREEN_HEIGHT = 750;
    constexpr int CELL_SIZE = 30;
    constexpr int FPS = 12;

    //Window initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game of life");
    SetTargetFPS(FPS);

    Simulation sim(SCREEN_WIDTH, SCREEN_HEIGHT, CELL_SIZE);
    
    sim.setValue(5, 9, true);
    sim.setValue(5, 10, true);

    while (!WindowShouldClose())
    { 
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    
    CloseWindow();
}