//
// Created by laugh on 03/07/2023.
//

#include "../include/Game.hpp"
#include "../include/Settings.hpp"
#include <raylib.h>
#include <cassert>

Game::Game(int width, int height, int fps, const std::string& title) :
board(settings::boardPosition, settings::boardWidthHeight,
      settings::cellSize, settings::padding)
{
    assert(!IsWindowReady());
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
    for (int iY = 0; iY < 20; iY++)
        for (int iX = 0; iX < 10; iX++)
            board.SetCell({iX, iY}, RED);
}
Game::~Game() noexcept {
    assert(IsWindowReady());
    CloseWindow();
}

bool Game::GameShouldClose() const
{
    return WindowShouldClose();
}

void Game::Tick()
{
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}

void Game::Draw()
{
    ClearBackground(BLACK);
    board.Draw();
}

void Game::Update()
{

}
