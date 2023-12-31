//
// Created by laugh on 03/07/2023.
//

#ifndef TETRIS_SETTINGS_HPP
#define TETRIS_SETTINGS_HPP

#include "Vec2.hpp"

namespace settings
{
    // Window settings
    inline constexpr int screenWidth = 800;
    inline constexpr int screenHeight = 600;
    inline constexpr int fps = 60;

    // Board settings
    inline constexpr int cellSize = 23;
    inline constexpr int padding = 2;
    inline constexpr Vec2<int> boardPosition{250, 70};
    inline constexpr Vec2<int> boardWidthHeight{10, 20};
}

#endif //TETRIS_SETTINGS_HPP
