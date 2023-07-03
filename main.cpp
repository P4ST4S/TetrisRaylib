#include "raylib.h"
#include "include/Game.hpp"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int fps = 60;

    Game game{screenWidth, screenHeight, fps,  "Tetris Raylib"};

    while (!game.GameShouldClose())
        game.Tick();

    return 0;
}
