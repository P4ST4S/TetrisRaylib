//
// Created by laugh on 03/07/2023.
//

#include "../include/Game.hpp"


Game::Game(int width, int height, int fps, const std::string& title) :
board(settings::boardPosition, settings::boardWidthHeight,
      settings::cellSize, settings::padding), tetromino(board)
{
    assert(!IsWindowReady());
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
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
    tetromino.Draw();
}

void Game::Update()
{

}
