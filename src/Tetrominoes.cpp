//
// Created by laugh on 03/07/2023.
//

#include "../include/Tetrominoes.hpp"

Tetromino::Tetromino(const bool *shape_in, int dimension_in, Color color_in, const Board& board_in) :
shape(shape_in), dimension(dimension_in), color(color_in),
boardPos(board_in.GetWidth() / 2 - dimension_in / 2, 0), board(board_in),
currentRotation(Rotation::UP)
{}

void Tetromino::Draw() const
{
    for (int y = 0; y < dimension; y++)
        for (int x = 0; x < dimension; x++) {
            bool cell = false;
            switch (currentRotation) {
                case Rotation::UP:
                    cell = shape[y * dimension + x];
                    break;
                case Rotation::RIGHT:
                    cell = shape[dimension * (dimension - 1) - dimension * x + y];
                    break;
                case Rotation::DOWN:
                    cell = shape[(dimension * dimension - 1) - dimension * y - x];
                    break;
                case Rotation::LEFT:
                    cell = shape[dimension - 1 + dimension * x - y];
                    break;
                default:
                    break;
            }
            if (cell)
                board.DrawCell(boardPos + Vec2<int>{x, y}, color);
        }
}

void Tetromino::RotateClockwise()
{
    currentRotation = Rotation((int(currentRotation) + 1) % 4);
}

void Tetromino::RotateCounterClockwise()
{
    if (currentRotation == Rotation::UP)
        currentRotation = Rotation::LEFT;
    else
        currentRotation = Rotation(int(currentRotation) - 1);
}
