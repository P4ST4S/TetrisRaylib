//
// Created by laugh on 03/07/2023.
//

#include "../include/Game.hpp"
#include <raylib.h>
#include <assert.h>

Game::Game(int width, int height, int fps, const std::string& title)
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
    ClearBackground(RAYWHITE);
}

void Game::Update()
{

}
