#include "grid.h"
#include "iostream"
#include "colors.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
};

void Grid::Initialize()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        };
    };
};

void Grid::Draw()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize -1, colors[cellValue]);
        };
    };
};
bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
};

bool Grid::IsCellEmpty(int row, int column){  //check if cell value == 0 
    if(grid[row][column] == 0){
        return true;
    };
    return false;
};

bool Grid::IsRowFull(int row){ //check if the values of the row is 0 or not
    for(int column = 0; column < numCols ;column++){
        if(grid[row][column] == 0){
            return false;
        };
    };
    return true;
};

void Grid::ClearRow(int row){  //all the cells of row will contain the value 0 
    for(int column ;column < numCols; column++){
        grid[row][column] = 0;
    };
};

void Grid::MoveRowDown(int row, int numRows){ 
    for(int column; column < numCols; column++){
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0; 
    };
};

int Grid::ClearFullRows(){  //clear all completed rows
    int completed = 0;
    for(int row = numRows-1; row > 0; row--){
        if(IsRowFull(row)){
            ClearRow(row);
            completed++ ;
        }
        else if(completed > 0){
            MoveRowDown(row, completed);
        };
    };
    return completed;
};