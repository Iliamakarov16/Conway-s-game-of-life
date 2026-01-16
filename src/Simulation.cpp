#include "Simulation.hpp"
#include <utility>
#include <vector>

void Simulation::draw(){
    grid.draw();
}

void Simulation::setValue(const int& row, const int& col, const bool& val){
    grid.setValue(row, col, val);
}

bool Simulation::getValue(const int& row, const int& col) const{
    return grid.getValue(row, col);
}

int Simulation::countLiveNeighbors(int row, int col){
    int count = 0;
    std::vector<std::pair<int, int>> neighborsOffset = {
        {-1, 0}, // above
        {1, 0},  // below
        {0, 1},  // right
        {0, -1}, // left
        {-1, 1}, // upper right
        {-1, -1}, // upper left
        {1, 1},  // lower right
        {1, -1}  // lower left
    };

    for (const auto& offset : neighborsOffset){
        if (getValue((row + offset.first + grid.getRows()) % grid.getRows(), 
           (col + offset.second + grid.getCols()) % grid.getCols())){
            count++;
        }
    }
    
    return count;
}

void Simulation::update(){
    for (int row = 0; row < grid.getRows(); row++){
        for(int col = 0; col < grid.getCols(); col++){

            int liveNeighbors = countLiveNeighbors(row, col);
            bool cellValue = grid.getValue(row, col);

            if (cellValue){

                if (liveNeighbors > 3 || liveNeighbors < 2){
                    tempGrid.setValue(row, col, false);
                }
                else{
                    tempGrid.setValue(row, col, true);
                }
            }
            else{

                if (liveNeighbors == 3){
                    tempGrid.setValue(row, col, true);
                }
                else{
                    tempGrid.setValue(row, col, false);
                }
            }
        }
    }
    grid = tempGrid;
}

void Simulation::toggleCell(const int& row, const int& col){
    grid.toggleCell(row, col);
}

void Simulation::simCommands(){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !isActive){
        Vector2 mousePos = GetMousePosition();
        toggleCell(mousePos.x, mousePos.y);
    }

    if (IsKeyPressed(KEY_ENTER)){//starts and stops simulation
        changeGameState();
    }

    if(IsKeyPressed(KEY_E)){//increase fps
        int fps = GetFPS();
        fps += 1;
        SetTargetFPS(fps);
    }
    else if(IsKeyPressed(KEY_Q)){//decrease fps
        int fps = GetFPS();
        fps -= 1;
        SetTargetFPS(fps);
    }

    if(IsKeyPressed(KEY_R) && !isActive){//randomize grid
        grid.fillRand();
    }

    if(IsKeyPressed(KEY_C) && !isActive){//clear grid
        grid.clear();
    }
}