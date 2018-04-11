#include "Entity.h"
#include <iostream>
namespace Core
{
    Entity::Entity(const char* name, maths::vec2 position)
        : m_Name(name), m_position(position)
    {
        std::cout << "Created the Entity object!" << std::endl;
    }

    void Entity::Move(maths::vec2 delta)
    {
        m_position += delta;
    }
}