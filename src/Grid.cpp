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
    if (isValidCell(row, col)){
        cells_[row][col] = val;
    }
}

bool Grid::getValue(const int& row, const int& col) const{
    if (isValidCell(row, col)){
        return cells_[row][col];
    }


}
bool Grid::isValidCell(const int&  row, const int&  col) const{
    if ((row < rows_ || row >= 0) || (col < columns_ || col >= 0)) return true;

    return false;
}

void Grid::fillRand(){
    for (int row = 0; row < rows_; row++){
        for (int col = 0; col < columns_; col++){
            bool randVal = GetRandomValue(0, 4);
            cells_[row][col] = (randVal == 4) ? 1 : 0;
        }
    }
}