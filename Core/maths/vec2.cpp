#include "vec2.h"

namespace maths
{
    vec2::vec2()
    {
        x = 0.0f;
        y = 0.0f;
    }

    vec2::vec2(const float & x, const float & y)
    {
        this->x = x;
        this->y = y;
    }

    vec2& vec2::Add(const vec2 & other)
    {
        this->x += other.x;
        this->y += other.y;

        return *this;
    }

    vec2& vec2::Subtract(const vec2 & other)
    {
        this->x += other.x;
        this->y += other.y;

        return *this;
    }

    vec2& vec2::Multiply(const vec2 & other)
    {
        this->x += other.x;
        this->y += other.y;

        return *this;
    }

    vec2& vec2::Divide(const vec2 & other)
    {
        this->x += other.x;
        this->y += other.y;

        return *this;
    }

    vec2& operator+(vec2 left, const vec2& right)
    {
        return left.Add(right);
    }

    vec2& operator-(vec2 left, const vec2& right)
    {
        return left.Subtract(right);
    }

    vec2& operator*(vec2 left, const vec2& right)
    {
        return left.Multiply(right);
    }

    vec2& operator/(vec2 left, const vec2& right)
    {
        return left.Divide(right);
    }

    bool vec2::operator==(const vec2 & other)
    {
        return x == other.x && y == other.y;
    }

    bool vec2::operator!=(const vec2 & other)
    {
        return !(*this == other);
    }

    vec2 & vec2::operator+=(const vec2 & other)
    {
        return Add(other);
    }

    vec2 & vec2::operator-=(const vec2 & other)
    {
        return Subtract(other);
    }

    vec2 & vec2::operator*=(const vec2 & other)
    {
        return Multiply(other);
    }

    vec2 & vec2::operator/=(const vec2 & other)
    {
        return Divide(other);
    }

    std::ostream& operator<<(std::ostream& stream, const vec2& vector)
    {
        return stream << "vec2(" << vector.x << "," << vector.y << ")";
    }
}