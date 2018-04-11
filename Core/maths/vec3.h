#pragma once
#include <iostream>
#include "../export_api.h"

namespace maths
{
    struct CORE_API vec3
    {
        float x, y, z;

        vec3();
        vec3(const float &x, const float &y, const float &z);

        vec3& Add(const vec3& other);
        vec3& Subtract(const vec3& other);
        vec3& Multiply(const vec3& other);
        vec3& Divide(const vec3& other);

        friend vec3& operator+(vec3 left, const vec3& right);
        friend vec3& operator-(vec3 left, const vec3& right);
        friend vec3& operator*(vec3 left, const vec3& right);
        friend vec3& operator/(vec3 left, const vec3& right);

        bool operator==(const vec3& other);
        bool operator!=(const vec3& other);

        vec3& operator+=(const vec3& other);
        vec3& operator-=(const vec3& other);
        vec3& operator*=(const vec3& other);
        vec3& operator/=(const vec3& other);

        friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
    };
}