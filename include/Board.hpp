//
// Created by laugh on 03/07/2023.
//

#ifndef TETRIS_BOARD_HPP
#define TETRIS_BOARD_HPP

#include "raylibCpp.hpp"
#include <vector>

#include "Vec2.hpp"

class Board {
private:
    class Cell {
    public:
        Cell();

        void SetColor(Color c_in);
        Color GetColor() const;
        void Remove();
    private:
        bool bExists;
        Color c;
    };

public:
    Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellSize, int padding);

    void SetCell(Vec2<int> pos, Color c);
    void DrawCell(Vec2<int> pos) const;
    void DrawBorder() const;
    void Draw() const;

private:
    std::vector<Cell> cells;
    const int width;
    const int height;
    const int cellSize;
    const int padding;
    Vec2<int> screenPos;
};


#endif //TETRIS_BOARD_HPP
