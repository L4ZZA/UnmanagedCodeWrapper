#pragma once

#include "ManagedObject.h"
#include "../Core/Core.h"

using namespace System;

namespace CLIWrapper
{
    public ref class Entity : public ManagedObject<Core::Entity>
    {
    public:

        // Constructor
        // String^ -> indicates that the lifetime of a string object is to be managed automatically [handle-to-object (^) modifier].
        Entity(String^ name, float xPos, float yPos);

        void Move(float deltaX, float deltaY);

        // X Position 
        property float XPosition
        {
        public:
            float get() { return m_Instance->GetXPosition(); }

        private:
            void set(float value) {}
        }

        // Y Position
        property float YPosition
        {
        public:
            float get() { return m_Instance->GetYPosition(); }

        private:
            void set(float value) {}
        }
}