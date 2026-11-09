#include<raylib.h>
#include "game.h"

double LastUpdateTime = 0;
bool EventTriggered(double interval)  // Checks if the specified time interval has passed
{
    double currentTime = GetTime();
    if(currentTime - LastUpdateTime >= interval){
        LastUpdateTime = currentTime;
        return true;
    };
    return false;
};

int main()
{
    InitWindow(300, 600, "Tetris Game !");
    SetTargetFPS(60);

    Game game = Game();

    while(!WindowShouldClose())
    {
        //updating
        game.handleInput();
        if(EventTriggered(0.2)){
            game.MoveBlockDown();
        };
        BeginDrawing();
        ClearBackground(DARKBLUE);

        //Drawing
        game.Draw();

        EndDrawing();
    };

    CloseWindow();
    return 0;
};