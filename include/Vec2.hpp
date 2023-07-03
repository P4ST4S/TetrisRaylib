//
// Created by laugh on 03/07/2023.
//

#ifndef TETRIS_VEC2_HPP
#define TETRIS_VEC2_HPP

template <typename T>
class Vec2 {
public:
    Vec2() = default;
    Vec2(T x_in, T y_in) : x(x_in), y(y_in) {}

    T GetX() const { return x; };
    T GetY() const { return y; };

    void SetX(T x_in) { x = x_in; };
    void SetY(T y_in) { y = y_in; };

public:
    bool operator==(const Vec2& rhs)
    {
        return (x == rhs.x && y == rhs.y);
    }
    bool operator!=(const Vec2& rhs)
    {
        return *this != rhs;
    }

    Vec2 operator+(const Vec2& rhs) const
    {
        return {x + rhs.x, y + rhs.y};
    }
    Vec2 operator+(const int rhs) const
    {
        return {x + rhs, y + rhs};
    }
    Vec2& operator+=(const Vec2 rhs)
    {
        return *this = *this + rhs;
    }

    Vec2 operator-(const Vec2& rhs) const
    {
        return {x - rhs.x, y - rhs.y};
    }
    Vec2 operator-(const int rhs) const
    {
        return {x - rhs, y - rhs};
    }
    Vec2& operator-=(const Vec2 rhs)
    {
        return *this = *this - rhs;
    }

    Vec2 operator*(const Vec2& rhs) const
    {
        return {x * rhs.x, y * rhs.y};
    }
    Vec2 operator*(const int rhs) const
    {
        return {x * rhs, y * rhs};
    }
    Vec2& operator*=(const Vec2 rhs)
    {
        return *this = *this * rhs;
    }

private:
    T x;
    T y;
};


#endif //TETRIS_VEC2_HPP
