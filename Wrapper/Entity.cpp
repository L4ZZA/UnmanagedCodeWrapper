#include "stdafx.h"
#include "Entity.h"

namespace CLIWrapper
{
    // Contructor
    Entity::Entity(String^ name, float xPos, float yPos)
        : ManagedObject(new Core::Entity(string_to_char_array(name), xPos, yPos))
    {
        Console::WriteLine("Creating a new Entity-wrapper object!");
    }

    void Entity::Move(float deltaX, float deltaY)
    {
        //Console::WriteLine("The Move method from the Wrapper was called!");
        m_Instance->Move(deltaX, deltaY);
    }
}