#pragma once
#include "Grid.hpp"

class Simulation{
private:
    Grid grid;
public:
    Simulation(const int&  rows, const int&  cols, const int& cellSize) : grid(rows, cols, cellSize){};
    
    void draw();
    void setValue(const int&  row, const int&  col, const bool& val);
    bool getValue(const int&  row, const int&  col) const;

    int countLiveNeighbors(int row, int col);
};