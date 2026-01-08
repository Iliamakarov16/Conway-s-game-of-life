#include "Grid.hpp"

void Grid::draw(){
    for (int row = 0; row < rows_; row++){
        for(int col = 0; col < columns_; col++){
            Color color = cells_[row][col] ? GREEN : Color{40, 40, 40, 255};
            DrawRectangle(row * cellSize_, col * cellSize_, cellSize_ - 1, cellSize_ - 1, color);
        }
    }
}

void Grid::setValue(const int& row, const int&  col, const bool&  val){
    if ((row > rows_ || row < 0) || (col > columns_ || col < 0)) throw std::out_of_range("Cell does not exist");

    cells_[row][col] = val;
}

bool Grid::getValue(const int& row, const int& col) const{
    if ((row > rows_ || row < 0) || (col > columns_ || col < 0)) throw std::out_of_range("Cell does not exist");
    
    return cells_[row][col];
}