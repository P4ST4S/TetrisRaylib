#include "raylib.h"
#include "include/Game.hpp"
#include "include/Settings.hpp"

int main()
{
    Game game{settings::screenWidth, settings::screenHeight, settings::fps,  "Tetris Raylib"};

    while (!game.GameShouldClose())
        game.Tick();

    return 0;
}
