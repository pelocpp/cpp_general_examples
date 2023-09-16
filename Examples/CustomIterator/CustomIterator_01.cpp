// ===============================================================================
// CustomIterator_01.cpp // Demo Custom Iterator Implementation
// Using Nested Class Approach
// ===============================================================================

#include <iostream>
#include <algorithm>
#include <iterator>

class MyAwesomeData
{
private:
    int m_01_data = 1;
    int m_02_data = 2;
    int m_03_data = 3;

    class MyAwesomeData_Iterator
    {
        using value_type = int;
        using difference_type = size_t;
        using iterator_category = std::forward_iterator_tag;
        using pointer = int*;
        using reference = int&;

    public:
        MyAwesomeData& m_cont;

        // Design Entscheidung: 0 == data_1, 1 == data_2, 2 == data_3, -1 == leer / Ende
        int m_pos;

    public:
        MyAwesomeData_Iterator(MyAwesomeData& cont)
            : m_cont{ cont }, m_pos(-1) {
        }

        int operator* () {

            // return element at position 'm_pos'
            switch (m_pos)
            {
            case 0:
                return m_cont.m_01_data;
                break;
            case 1:
                return m_cont.m_02_data;
                break;
            case 2:
                return m_cont.m_03_data;
                break;
            default:
                // throw
                break;
            }
            // throw
            return 0;
        }

        void operator++ () {

            if (m_pos < 2) {
                m_pos++;
            }
            else {
                m_pos = -1;
            }
        }

        bool operator == (const MyAwesomeData_Iterator& other) {
            return ! (*this != other);
        }

        bool operator != (const MyAwesomeData_Iterator& other) {
            return m_pos != other.m_pos;
        }
    };

public:

    MyAwesomeData_Iterator begin() {

        MyAwesomeData_Iterator tmp(*this);
        tmp.m_pos = 0;
        return tmp;
    };

    MyAwesomeData_Iterator end() {

        MyAwesomeData_Iterator tmp(*this);  // m_pos == -1
        return tmp;
    }
};


void main_iterators_01()
{
    MyAwesomeData data;

    // using STL algorithm
    std::for_each(
        data.begin(),
        data.end(),
        [](const auto& elem) {
            std::cout << elem << ' ';
        }
    );
    std::cout << std::endl;

    // using range based loop
    for (auto elem : data) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

void main_iterators_02()
{
    MyAwesomeData data;

    auto p = std::minmax(data.begin(), data.end(), [](const auto& left, const auto& right ) {

        if (left.m_pos == -1)
            return false;

        if (right.m_pos == -1)
            return false;

        return left.m_pos < right.m_pos;
    });
}

void main_custom_iterator_01() {

    main_iterators_01();
    main_iterators_02();
}

// ===============================================================================
// End-of-File
// ===============================================================================
