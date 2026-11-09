#include "game.h"
#include <random>
#include "iostream"

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
}

Block Game::GetRandomBlock()
{
    if(blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = std::rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;

};

std::vector<Block> Game::GetAllBlocks()
{
    return {LBlock(), IBlock(), TBlock(), OBlock(), JBlock(), SBlock(), ZBlock()};
};

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
};

void Game::handleInput()
{
    int KeyPressed = GetKeyPressed();

    if(KeyPressed != 0 && gameOver){
        gameOver = false;
        Reset();
    };
    
    switch(KeyPressed)
    {
        case KEY_LEFT : MoveBlockLeft();
        break;
        case KEY_RIGHT : MoveBlockRight();
        break;
        case KEY_R : RotateBlock();
        break;
    };
    
};

void Game::Reset(){
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
};

void Game::MoveBlockLeft()
{
    if(!gameOver){
        currentBlock.Move(0 ,-1);   
        if(IsBlockOutside() || BlockFits() == false){
            currentBlock.Move(0, 1);
        };
    }
};

void Game::MoveBlockRight()
{
    if(!gameOver){
        currentBlock.Move(0 ,1);
        if(IsBlockOutside() || BlockFits() == false){
            currentBlock.Move(0, -1);
        };
    };
};

void Game::MoveBlockDown()
{
    if(!gameOver){
        currentBlock.Move(1, 0);
        if(IsBlockOutside() || BlockFits() == false){
            currentBlock.Move(-1, 0);
            LockBlock();
        };
        grid.ClearFullRows();
    };
};

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item :tiles){
        if(grid.IsCellOutside(item.row, item.column)){
            return true;
        }
    }
    return false;
}

void Game::RotateBlock() 
{
    if(!gameOver){
        currentBlock.Rotate();
        if(IsBlockOutside()){
            currentBlock.UndoRotation();
        };
    };
};

void Game::LockBlock() //go to next block if a collision accurred between currentblock and another block or the current block arrived in the bottom  
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();

    for(Position item : tiles)
    {
        grid.grid[item.row][item.column] = currentBlock.id;  

    };
    currentBlock = nextBlock;
    if(BlockFits() == false){
        currentBlock.Move(-1, 0);
        gameOver = true;    
    };
    nextBlock = GetRandomBlock();
};

bool Game::BlockFits(){ //check collision between the blocks (if the value of all cells of block is 0)
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles){
        if(grid.IsCellEmpty(item.row, item.column) == false){
            return false;
        };
    };
    return true;
};

