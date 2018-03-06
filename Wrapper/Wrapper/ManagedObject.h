#pragma once
using namespace System;
using namespace System::Runtime::InteropServices;

namespace CLIWrapper
{

    template<class T>
    public ref class ManagedObject
    {

    public:
        // Constructor
        ManagedObject(T* instance)
            : m_Instance(instance)
        { }

        // Destructor
        virtual ~ManagedObject()
        {
            if (m_Instance != nullptr)
            {
                delete m_Instance;
            }
        }

        // Finalizer
        !ManagedObject()
        {
            if (m_Instance != nullptr)
            {
                delete m_Instance;
            }
        }

        // get instance of the object
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