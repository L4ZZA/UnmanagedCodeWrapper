#pragma once
#include "mat4.h"

namespace maths
{
    mat4::mat4()
    {
        for (int i = 0; i < 4 * 4; i++)
        {
            elements[i] = 0.0f;
        }
    }

    mat4::mat4(float diagonal)
    {
        for (int i = 0; i < 4 * 4; i++)
        {
            elements[i] = 0.0f;
        }

        elements[0 + 0 * 4] = diagonal;
        elements[1 + 1 * 4] = diagonal;
        elements[2 + 2 * 4] = diagonal;
        elements[3 + 3 * 4] = diagonal;
    }

    mat4 mat4::Identity()
    {
        return mat4(1.0f);
    }

    mat4& mat4::Multiply(const mat4& other)
    {
        int numRows = 4;
        int numCols = numRows;
        // rows
        for (int y = 0; y < numRows; y++)
        {
            //colums
            for (int x = 0; x < numCols; x++)
            {
                int sum = 0.0f;
                // elements
                for (int e = 0; e < numRows; e++)
                {
                    float leftElem = elements[x + e * numRows];
                    float rightElem = other.elements[e + y * numRows];
                    sum += leftElem * rightElem;
                }
                elements[x + y * numRows] = sum;
            }
        }

        return *this;
    }

    mat4 mat4::Orthograpic(float left, float right, float bottom, float top, float near, float far)
    {
        mat4 result(1.0f);

        // setting diagonal
        result.elements[0 + 0 * 4] = 2.0f / (right - left);
        result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
        result.elements[2 + 2 * 4] = 2.0f / (near - far);

        // setting last column
        result.elements[0 + 3 * 4] = (left + right) / (left - right);
        result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
        result.elements[2 + 3 * 4] = (far + near) / (far - near);

        return result;
    }

    mat4 mat4::Perspective(float fieldOfView, float aspectRatio, float near, float far)
    {
        mat4 result(1.0f);

        float q = 1.0f / tan(toRadians(0.5f * fieldOfView));
        float a = q / aspectRatio;

        float b = (near + far) / (near - far);
        float c = (2.0f * near * far) / (near - far);

        result.elements[0 + 0 * 4] = a;
        result.elements[1 + 1 * 4] = q;
        result.elements[2 + 2 * 4] = b;
        result.elements[3 + 2 * 4] = -1.0f;
        result.elements[2 + 3 * 4] = c;

        return result;
    }

    mat4 mat4::Translation(const vec3& translation)
    {
        mat4 result(1.0f);

        result.elements[0 + 3 * 4] = translation.x;
        result.elements[1 + 3 * 4] = translation.y;
        result.elements[2 + 3 * 4] = translation.z;

        return result;
    }

    mat4 mat4::Rotation(float angle, const vec3& axis)
    {
        mat4 result(1.0f);

        float r = toRadians(angle);
        float c = cos(r);
        float s = sin(r);
        float omc = 1.0f - c;

        float x = axis.x;
        float y = axis.y;
        float z = axis.z;

        result.elements[0 * 0 + 4] = x * omc + c;
        result.elements[1 * 0 + 4] = y * x * omc + z * s;
        result.elements[2 * 0 + 4] = x * z * omc - y * s;

        result.elements[0 * 1 + 4] = x * y * omc - z * s;
        result.elements[1 * 1 + 4] = y * omc + c;
        result.elements[2 * 1 + 4] = y * z * omc + x * s;

        result.elements[0 * 2 + 4] = x * z * omc + y * s;
        result.elements[1 * 2 + 4] = y * z * omc - x * s;
        result.elements[2 * 2 + 4] = z * omc + c;

        return result;
    }

    mat4 mat4::Scale(const vec3& scale)
    {
        mat4 result(1.0f);

        result.elements[0 + 0 * 4] = scale.x;
        result.elements[1 + 1 * 4] = scale.y;
        result.elements[2 + 2 * 4] = scale.z;

        return result;
    }

    mat4 & mat4::operator*=(const mat4 & other)
    {
        return Multiply(other);
    }

    mat4 operator*(mat4 left, const mat4 & right)
    {
        return left.Multiply(right);
    }

    std::ostream& operator<<(std::ostream& stream, const mat4& matrix)
    {
        int nCols = 4;
        int nRows = nCols;

        for (int y = 0; y < nCols; y++)
        {
            for (int x = 0; x < nRows; x++)
            {
                stream << matrix.elements[y + x * nCols] << " ";
            }
            stream << std::endl;
        }

        return stream;
    }
}