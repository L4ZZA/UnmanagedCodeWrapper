#pragma once
#include "../ManagedObject.h"
#include "Core.h"

using namespace System;

namespace CLIWrapper
{
    // See this docs
    // https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp
    public ref class Vec2 : public ManagedObject<core::maths::vec2>
    {
    public:

        // Constructor
        Vec2();
        Vec2(float xPos, float yPos);
        Vec2(const Vec2^ other);

        // X Position 
        property float X
        {
        public:
            float get() { return m_Instance->x; }

        private:
            void set(float value) {}
        }

        // Y Position
        property float Y
        {
        public:
            float get() { return m_Instance->y; }

        private:
            void set(float value) {}
        }

        void Add(Vec2 other);
        void Subtract(Vec2 other);
        void Multiply(Vec2 other);
        void Divide(Vec2 other);

        //TODO:
        //friend vec2& operator+(vec2 left, const vec2& right);
        //friend vec2& operator-(vec2 left, const vec2& right);
        //friend vec2& operator*(vec2 left, const vec2& right);
        //friend vec2& operator/(vec2 left, const vec2& right);

        //bool operator==(const vec2& other);
        //bool operator!=(const vec2& other);

        //vec2& operator+=(const vec2& other);
        //vec2& operator-=(const vec2& other);
        //vec2& operator*=(const vec2& other);
        //vec2& operator/=(const vec2& other);

        //friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
    };
}