//
// Created by laugh on 03/07/2023.
//

#include <cassert>
#include "../include/raylibCpp.hpp"

void raycpp::DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color)
{
    assert(pos.GetX() >= 0 && pos.GetY() >= 0);
    assert(pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight());
    DrawRectangle(pos.GetX(), pos.GetY(), widthHeight.GetX(), widthHeight.GetY(), color);
}
