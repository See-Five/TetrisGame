#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
public:
    Block();
    int id; //type of block (T block, I bloch ....)
    std::map<int, std::vector<Position>> cells; 
    // what's map !! : Key0 --> value0 ; int --> vector
    // Key is the rotation state of the block .ex: 0 --> {{0,1}, {1,0}, {1,1}, {1,2}}

    void Draw();
    void Move(int rows, int columns);
    void Rotate();
    void UndoRotation();
    std::vector<Position> GetCellPositions();

private:
    int cellSize;
    int rotationState;    
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;

};