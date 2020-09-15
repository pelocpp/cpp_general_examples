// ===========================================================================
// SmartPointerImpl.cpp // Smart Pointer Demo Implementation
// ===========================================================================

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

#include <iostream>
#include <stdexcept>

#include "Dummy.h"

namespace SmartPointerDemo {

    template <typename T>
    class SmartPointer
    {
    private:
        class ReferenceCounter
        {
        private:
            int m_count; // reference counter of corresponding 'raw pointer'

        public:
            ReferenceCounter () : m_count(0) {}

            void addRef() {
                m_count++;  // increment reference count
            }

            int release() {
                m_count--;      // decrement and ...
                return m_count; // ... return the reference count
            }

            int getUsageCount() const { return m_count; }
        };

        T* m_pointer;
        ReferenceCounter* m_reference;

        void release() {
            int counter = m_reference->release();
            
            std::cerr 
                << "releasing SmartPointer ["
                << counter << " references active]: " 
                << std::endl;

            if (counter == 0) {
                delete m_reference;
                delete m_pointer;
            }
        }

    public:
        explicit SmartPointer(T* ptr) { 
            m_reference = new ReferenceCounter();
            m_reference->addRef();
            m_pointer = ptr;
        }

        SmartPointer(SmartPointer const& other) {
            m_reference = other.m_reference;  // just copy pointer!
            m_pointer = other.m_pointer;      // just copy pointer!
            m_reference->addRef();
        }

        ~SmartPointer() {
            std::cerr << "d'tor SmartPointer" << std::endl;
            release();
        }

        SmartPointer& operator=(SmartPointer const& rhs){

            if (this == &rhs) {
                return *this;
            }

            // release ownership of current raw pointer 
            release();

            m_reference = rhs.m_reference; // just copy pointer!
            m_pointer = rhs.m_pointer;     // just copy pointer!

            m_reference->addRef();

            return *this;
        }

        T* operator->() const {
            return m_pointer; 
        }

        unsigned int usageCount() const {
            return m_reference->getUsageCount();
        }
    };

    void test_01() {
        SmartPointer<Dummy> sp(new Dummy);
        std::cerr << "Usage Count: " << sp.usageCount() << std::endl;
        sp->sayHello();
    }


    void test_02() {
        SmartPointer<Dummy> sp1(new Dummy(1));
        std::cerr << "Counter [sp1]: " << sp1.usageCount() << std::endl;

        SmartPointer<Dummy> sp2(new Dummy(2));
        std::cerr << "Counter [sp2]: " << sp2.usageCount() << std::endl;

        // testing smart pointer assigment operator
        sp2 = sp1; 
    }

    void test_03() {

        SmartPointer<Dummy> sp1(new Dummy);
        std::cerr << "Counter [sp1]: " << sp1.usageCount() << std::endl;

        // testing smart pointer copy constructor
        SmartPointer<Dummy> sp2(sp1);
        std::cerr << "Counter [sp2]: " << sp2.usageCount() << std::endl;
    }

    void test_04() {
        // tiny stress test :-)
        SmartPointer<Dummy> sp1(new Dummy);
        sp1->sayHello();
        SmartPointer<Dummy> sp2(sp1);
        SmartPointer<Dummy> sp3(sp1);
        SmartPointer<Dummy> sp4(sp1);
        SmartPointer<Dummy> sp5(sp1);
        sp4 = sp1;
        sp5 = sp1;
    }
}

void main_smart_pointer ()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    using namespace SmartPointerDemo;
    test_01();
    test_02();
    test_03();
    test_04();
}

// ===========================================================================
// End-of-File
// ===========================================================================
