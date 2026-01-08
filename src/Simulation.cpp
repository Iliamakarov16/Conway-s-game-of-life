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
    std::vector<std::pair<int, int>> neighbors = 
    {
        {row + 1, col},//above
        {row - 1, col},//below
        {row, col + 1},//right
        {row, col - 1},//left
        {row + 1, col + 1},//upper right
        {row + 1, col - 1},//upper left
        {row - 1, col + 1},//lower right
        {row - 1, col - 1}//lower left
    };

    for (const auto& neighbor : neighbors){
        if (getValue(neighbor.first, neighbor.second)){
            count++;
        }
    }
    
    return count;
}