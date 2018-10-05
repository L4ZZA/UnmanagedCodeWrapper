#pragma once
#include "vec3.h"
#include "maths_func.h"
#include "../export_api.h"

namespace maths
{
    struct CORE_API mat4
    {
        float elements[4 * 4];

        mat4();
        mat4(float diagonal);

        static mat4 Identity();

        static mat4 Orthograpic(float left, float right, float bottom, float top, float near, float far);
        static mat4 Perspective(float fieldOfView, float apectRation, float near, float far);

        static mat4 Translation(const vec3& translation);
        static mat4 Rotation(float angle, const vec3& axis);
        static mat4 Scale(const vec3& scale);

        mat4& Multiply(const mat4& other);
        friend mat4 operator*(mat4 left, const mat4& right);
        friend std::ostream& operator<<(std::ostream& stream, const mat4& matrix);
        mat4& operator*=(const mat4& other);
    };
}