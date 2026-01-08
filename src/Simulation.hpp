#pragma once
#include "Grid.hpp"

class Simulation{
private:
    Grid grid;
    Grid tempGrid;
public:
    Simulation(const int&  rows, const int&  cols, const int& cellSize) 
    : grid(rows, cols, cellSize), tempGrid(rows, cols, cellSize){grid.fillRand();}
    
    void draw();
    void setValue(const int&  row, const int&  col, const bool& val);
    bool getValue(const int&  row, const int&  col) const;
    
    int countLiveNeighbors(int row, int col);
    void update();
};