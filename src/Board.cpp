//
// Created by laugh on 03/07/2023.
//

#include "../include/Board.hpp"
#include <cassert>

Board::Cell::Cell() : bExists(false), c(WHITE)
{
}

void Board::Cell::SetColor(Color c_in)
{
    c = c_in;
    bExists = true;
}

void Board::Cell::Remove()
{
    bExists = false;
}

Color Board::Cell::GetColor() const
{
    return c;
}


Board::Board(Vec2<int> screenPos_in, Vec2<int> widthHeight_in, int cellSize_in, int padding_in) :
screenPos(screenPos_in), width(widthHeight_in.GetX()), height(widthHeight_in.GetY()), cellSize(cellSize_in),
padding(padding_in)
{
    assert(width > 0 && height > 0);
    assert(cellSize > 0);
    cells.resize(width * height);
}

void Board::SetCell(Vec2<int> pos_in, Color c_in)
{
    assert(pos_in.GetX() >= 0 && pos_in.GetY() >= 0);
    assert(pos_in.GetX() < width && pos_in.GetY() < height);
    cells[width * pos_in.GetY() + pos_in.GetX()].SetColor(c_in);
}

void Board::DrawCell(Vec2<int> pos_in) const
{
    assert(pos_in.GetX() >= 0 && pos_in.GetY() >= 0);
    assert(pos_in.GetX() < width && pos_in.GetY() < height);
    Color c = cells[width * pos_in.GetY() + pos_in.GetX()].GetColor();
    Vec2<int> topLeft = screenPos + padding + (pos_in * cellSize);
    raycpp::DrawRectangle(topLeft, Vec2{cellSize, cellSize} - padding, c);
}

void Board::Draw() const
{
    for (int iY = 0; iY < height; iY++)
        for (int iX = 0; iX < width; iX++)
            DrawCell({iX, iY});
}

