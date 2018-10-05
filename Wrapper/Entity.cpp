#include "stdafx.h"
#include "Entity.h"
#include "maths\vec2.h"

namespace CLIWrapper
{
    // Contructor
    Entity::Entity(String^ name, float xPos, float yPos)
        : ManagedObject(new core::Entity(string_to_char_array(name), core::maths::vec2(xPos,yPos)))
    {
        Console::WriteLine("Creating a new Entity-wrapper object!");
    }

    void Entity::Move(float deltaX, float deltaY)
    {
        //Console::WriteLine("The Move method from the Wrapper was called!");
        m_Instance->Move(core::maths::vec2(deltaX, deltaY));
    }
}