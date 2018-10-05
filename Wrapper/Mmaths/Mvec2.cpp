#include "Mvec2.h"

namespace CLIWrapper
{
    // Contructor
    Vec2::Vec2()
        : ManagedObject(new core::maths::vec2())
    {
        Console::WriteLine("Vec2::Vec2()!");
    }
    // Contructor
    Vec2::Vec2(float xPos, float yPos)
        : ManagedObject(new core::maths::vec2(xPos, yPos))
    {
        Console::WriteLine("Vec2::Vec2(float xPos, float yPos)!");
    }

    Vec2::Vec2(const Vec2 ^ other)
        : ManagedObject(new core::maths::vec2(other->m_Instance->x, other->m_Instance->y))
    {
        Console::WriteLine("Vec2::Vec2(const Vec2 ^ other)!");
    }

    void Vec2::Add(Vec2 other)
    {
        X += other.X;
        Y += other.Y;
    }

    void Vec2::Subtract(Vec2 other)
    {
        X -= other.X;
        Y -= other.Y;
    }

    void Vec2::Multiply(Vec2 other)
    {
        X *= other.X;
        Y *= other.Y;
    }

    void Vec2::Divide(Vec2 other)
    {
        X /= other.X;
        Y /= other.Y;
    }
}
