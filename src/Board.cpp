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

bool Board::Cell::Exists() const
{
    return bExists;
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

void Board::DrawCell(Vec2<int> pos_in, Color color) const
{
    assert(pos_in.GetX() >= 0 && pos_in.GetY() >= 0);
    assert(pos_in.GetX() < width && pos_in.GetY() < height);
    Vec2<int> topLeft = screenPos + padding + (pos_in * cellSize);
    raycpp::DrawRectangle(topLeft, Vec2{cellSize, cellSize} - padding, color);
}

void Board::DrawCell(Vec2<int> pos_in) const
{
    Color color = cells[width * pos_in.GetY() + pos_in.GetX()].GetColor();
    DrawCell(pos_in, color);
}

void Board::DrawBorder() const
{
    raycpp::DrawRectangleLinesEx(screenPos - (cellSize / 2),
                                 Vec2{width * cellSize, height * cellSize} + cellSize,
                                 cellSize / 2,
                                 WHITE);
}

void Board::Draw() const
{
    for (int iY = 0; iY < height; iY++)
        for (int iX = 0; iX < width; iX++) {
            if (CellExists({iX, iY}))
                DrawCell({iX, iY});
        }
    DrawBorder();
}

bool Board::CellExists(Vec2<int> pos) const
{
    return cells[pos.GetY() * width + pos.GetX()].Exists();
}

int Board::GetWidth() const
{
    return width;
}

int Board::GetHeight() const
{
    return height;
}
