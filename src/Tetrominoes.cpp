//
// Created by laugh on 03/07/2023.
//

#include "../include/Tetrominoes.hpp"

Tetromino::Tetromino(const bool *shape_in, int dimension_in, Color color_in, const Board& board_in) :
shape(shape_in), dimension(dimension_in), color(color_in),
boardPos(board_in.GetWidth() / 2 - dimension_in / 2, 0), board(board_in)
{}

void Tetromino::Draw() const
{
    for (int y = 0; y < dimension; y++)
        for (int x = 0; x < dimension; x++) {
            bool cell = shape[y * dimension + x];
            if (cell)
                board.DrawCell(boardPos + Vec2<int>{x, y}, color);
        }
}
