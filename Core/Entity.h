#pragma once
#include "export_api.h"
#include "maths\maths.h"

namespace core
{
    class CORE_API Entity
    {
    public:
        const char* m_Name;
    private:
        maths::vec2 m_position;
    public:
        Entity(const char* name, maths::vec2 position);

        void Move(maths::vec2 delta);
        inline float GetXPosition() const { return m_position.x; };
        inline float GetYPosition() const { return m_position.y; };
    };
}