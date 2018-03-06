#pragma once
using namespace System;
using namespace System::Runtime::InteropServices;

namespace CLIWrapper
{
    //  Holds a pointer to an unmanaged object from the Core project
    template<class T>
    public ref class ManagedObject
    {

    public:
        ManagedObject(T* instance)
            : m_Instance(instance)
        {}

        // Destructor - called when object deleted
        virtual ~ManagedObject()
        {
            if (m_Instance != nullptr)
            {
                delete m_Instance;
            }
        }

        // Finalizer - called by the garbage collector 
        !ManagedObject()
        {
            if (m_Instance != nullptr)
            {
                delete m_Instance;
            }
        }

        T* GetInstance()
        {
            return m_Instance;
        }

    protected:
        T* m_Instance;

        // =================== Helper methods ===================
    public:

        static const char* string_to_char_array(String^ string)
        {
            const char* str = (const char*)(Marshal::StringToHGlobalAnsi(string)).ToPointer();
            return str;
        }
    };
}