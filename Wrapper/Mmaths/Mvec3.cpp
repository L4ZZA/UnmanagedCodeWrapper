#include "vec3.h"

namespace maths
{
    vec3::vec3()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    vec3::vec3(const float &x, const float &y, const float &z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    vec3& vec3::Add(const vec3 & other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;

        return *this;
    }

    vec3& vec3::Subtract(const vec3 & other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;

        return *this;
    }

    vec3& vec3::Multiply(const vec3 & other)
    {
        this->x *= other.x;
        this->y *= other.y;
        this->z *= other.z;

        return *this;
    }

    vec3& vec3::Divide(const vec3 & other)
    {
        this->x /= other.x;
        this->y /= other.y;
        this->z /= other.z;

        return *this;
    }

    vec3& operator+(vec3 left, const vec3& right)
    {
        return left.Add(right);
    }

    vec3& operator-(vec3 left, const vec3& right)
    {
        return left.Subtract(right);
    }

    vec3& operator*(vec3 left, const vec3& right)
    {
        return left.Multiply(right);
    }

    vec3& operator/(vec3 left, const vec3& right)
    {
        return left.Divide(right);
    }

    bool vec3::operator==(const vec3 & other)
    {
        return x == other.x && y == other.y;
    }

    bool vec3::operator!=(const vec3 & other)
    {
        return !(*this == other);
    }

    vec3 & vec3::operator+=(const vec3 & other)
    {
        return Add(other);
    }

    vec3 & vec3::operator-=(const vec3 & other)
    {
        return Subtract(other);
    }

    vec3 & vec3::operator*=(const vec3 & other)
    {
        return Multiply(other);
    }

    vec3 & vec3::operator/=(const vec3 & other)
    {
        return Divide(other);
    }

    std::ostream& operator<<(std::ostream& stream, const vec3& vector)
    {
        return stream << "vec3(" << vector.x << "," << vector.y << "," << vector.z << ")";
    }
}