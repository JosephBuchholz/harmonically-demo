#pragma once

#include "Converters.h"

/**
 * A structure that stores two values of type T.
 */
template<typename T>
struct Vec2
{
public:
    Vec2() {}
    Vec2(T x, T y) : x(x), y(y) {}
    Vec2(const Vec2<T>& obj) : x(obj.x), y(obj.y) {}

public:
    // Basic opperators
    Vec2<T> operator+(const Vec2<T>& rhs) const
    {
        return { this->x + rhs.x, this->y + rhs.y };
    }

    Vec2<T> operator-(const Vec2<T>& rhs) const
    {
        return { this->x - rhs.x, this->y - rhs.y };
    }

    Vec2<T> operator*(const Vec2<T>& rhs) const
    {
        return { this->x * rhs.x, this->y * rhs.y };
    }

    Vec2<T> operator/(const Vec2<T>& rhs) const
    {
        return { this->x / rhs.x, this->y / rhs.y };
    }

    Vec2<T> operator*(float rhs) const
    {
        return { this->x * rhs, this->y * rhs };
    }

    Vec2<T> operator/(float rhs) const
    {
        return { this->x / rhs, this->y / rhs };
    }

    bool operator==(const Vec2<T>& rhs) const
    {
        return (this->x == rhs.x) && (this->y == rhs.y);
    }

    Vec2<T>& operator+=(const Vec2<T>& rhs)
    {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        return *this;
    }

    Vec2<T>& operator-=(const Vec2<T>& rhs)
    {
        this->x = this->x - rhs.x;
        this->y = this->y - rhs.y;
        return *this;
    }

    Vec2<T>& operator*=(const Vec2<T>& rhs)
    {
        this->x = this->x * rhs.x;
        this->y = this->y * rhs.y;
        return *this;
    }

    Vec2<T>& operator/=(const Vec2<T>& rhs)
    {
        this->x = this->x / rhs.x;
        this->y = this->y / rhs.y;
        return *this;
    }

public:
    T x, y;
};