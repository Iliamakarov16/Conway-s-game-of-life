#pragma once 
#include "include/raylib.h"
#include <vector>
class Grid{
private:
    std::vector<std::vector<bool>> cells_;
    int rows_;
    int columns_;
    int cellSize_;
public:
    Grid(const int&  rows, const int& columns, const int& cellSize) 
    : rows_(rows/cellSize), columns_(columns/cellSize), cellSize_(cellSize), cells_(rows_, std::vector<bool>(columns_, 0)){};

    void draw();
    void setValue(const int& row, const int& col, const bool& val);
    bool getValue(const int& row, const int& col) const;
};