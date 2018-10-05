#pragma once
#include "../ManagedObject.h"
#include "Core.h"

using namespace System;

namespace CLIWrapper
{
    // See this docs
    // https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp
    public ref class Vec3 : public ManagedObject<core::maths::vec3>
    {
    public:

        // Constructor
        Vec3(float xPos, float yPos, float zPos);

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

        // Y Position
        property float Z
        {
        public:
            float get() { return m_Instance->z; }

        private:
            void set(float value) {}
        }
    };
}