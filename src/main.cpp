#include <iostream>
#include "include/raylib.h"
#include "Simulation.hpp"

int main() 
{
    constexpr int SCREEN_WIDTH = 750;
    constexpr int SCREEN_HEIGHT = 750;
    constexpr int CELL_SIZE = 25;
    int fps = 12;

    //Window initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game of life");
    SetTargetFPS(fps);

    Simulation sim(SCREEN_WIDTH, SCREEN_HEIGHT, CELL_SIZE);

    while (!WindowShouldClose())
    { 
        sim.simCommands();

        if (sim.isSimActive()){
            sim.update();
        }

        BeginDrawing();
        ClearBackground(BLACK);

        sim.draw();

        EndDrawing();
    }
    
    CloseWindow();
}