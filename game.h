#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game{
public:
    Game();
    Grid grid;
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void Draw();
    void handleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    bool gameOver;

private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    void LockBlock();
    bool IsBlockOutside();
    void RotateBlock();
    bool BlockFits();
    void Reset();
    
};