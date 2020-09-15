// ===========================================================================
// SubRange.cpp // Demonstration of Partial Template Specialization
// ===========================================================================

#include <iostream>
#include <stdexcept>

namespace SubRangeClassic {

    class SubRange {

    private:
        int m_min;
        int m_max;
        int m_value;

        void check(int value) {
            std::cerr << "calling check ..." << std::endl;
            if (value < m_min || value > m_max) {
                throw std::out_of_range("value not within range!");
            }
        }

    public:
        SubRange() = delete;

        SubRange(int value, int min, int max) : m_min(min), m_max(max) {
            check(value);
            m_value = value;
        }

        SubRange(SubRange const& other){
            m_min = other.m_min;
            m_max = other.m_max;
            m_value = other.m_value;
        }

        SubRange& operator= (SubRange const& other) {

            if (this == &other) {
                return *this;
            }

            // design decision: just copy value - dont't modify range
            check(other.m_value);
            m_value = other.m_value;

            return *this;
        }

        operator int() const {
            return m_value;
        }
    };

    void test_01_classic() {

        SubRange range1(10, 5, 20);
        SubRange range2(25, 15, 30);
        SubRange range3(8, 1, 10);

        // testing assignment
        std::cerr << range1 << std::endl;
        range1 = range3;
        std::cerr << range1 << std::endl;
        // range1 = range2;
        std::cerr << range1 << std::endl;

        // testing copy-c'tor
        SubRange range5(20, 10, 30);
        SubRange range6 = range5;
    }
}

namespace SubRangeWithTemplate {

    template <int MIN = 0, int MAX = 0> 
    class SubRange
    {
        int m_value;

        void check(int value) {
            std::cerr << "calling check ..." << std::endl;
            if (value < MIN || value > MAX) {
                throw std::out_of_range("value not within range!");
            }
        }

    public:
        SubRange() = delete;

        SubRange(int value) {
            check(value);
            m_value = value;
        }

        SubRange(SubRange const& other) {
            m_value = other.m_value;
        }

        SubRange& operator= (SubRange const& other) {
            // check not necessary (!)
            m_value = other.m_value;
            return *this;
        }

        operator int() const {
            return m_value;
        }
    };

    void test_02_template() {

        SubRange<5, 20>  range1(10);
        SubRange<15, 30> range2(25);
        SubRange<1, 10>  range3(8);
        SubRange<5, 20>  range4(15);

        // testing assignment
        std::cerr << range1 << std::endl;
        // range1 = range2;
        // range1 = range3;
        range1 = range4;
        std::cerr << range1 << std::endl;

        // testing copy-c'tor
        SubRange<15, 25> range5(20);
        // SubRange<10, 20> range6 = range5;
        SubRange<15, 25> range7 = range5;
    }
}

namespace SubRangeWithMetaProgramming {

    // (forward) declaration of function template 'check'
    template <bool>
    inline void check(int value, int min, int max);

    // template explicit specialization: value 'true'
    template <> 
    inline void check<true> (int value, int min, int max)
    {
        std::cerr << "calling check ..." << std::endl;
        if (value < min || value > max) {
            throw std::out_of_range("value not within range!");
        }
    }

    // template explicit specialization: value 'false'
    template <> 
    inline void check<false> (int, int, int) {}

    template <int MIN, int MAX>
    class SubRange
    {
        // needed for copy-c'tor and assignment operator
        template <int, int> friend class SubRange;

    private:
        int m_value;

    public:
        SubRange() = delete;

        SubRange(int value) {
            check<true>(value, MIN, MAX);
            m_value = value;
        }

        template <int MIN_OTHER, int MAX_OTHER>
        SubRange(SubRange<MIN_OTHER, MAX_OTHER> const& other)
        {
            check< (MIN_OTHER < MIN || MAX_OTHER > MAX) >(other.m_value, MIN, MAX);
            // or - without friend declaration
            // check< (MIN_OTHER < MIN || MAX_OTHER > MAX) >(other.getValue(), MIN, MAX);
            m_value = other.getValue();
        }

        template <int MIN_OTHER, int MAX_OTHER>
        SubRange& operator=(SubRange<MIN_OTHER, MAX_OTHER> const& other)
        {
            check< (MIN_OTHER < MIN || MAX_OTHER > MAX) >(other.m_value, MIN, MAX);
            // or - without friend declaration
            //check< (MIN_OTHER < MIN || MAX_OTHER > MAX) >(other.getValue(), MIN, MAX);
            m_value = other.getValue();
            return *this;
        }

        operator int() const
        {
            return m_value;
        }

        int getValue() const
        {
            return m_value;
        }
    };

    void test_03_metaprogramming() {

        SubRange<10, 20> range1(15);
        SubRange<11, 19> range2(16);
        SubRange<15, 25> range3(25);
        SubRange<10, 20> range4(16);

        // testing assignment
        std::cerr << range1 << std::endl;
        range1 = range2;
        std::cerr << range1 << std::endl;
        // range1 = range3;  // cannot be assigned
        std::cerr << range1 << std::endl;
        range1 = range4;
        std::cerr << range1 << std::endl;

        // testing copy-c'tor
        SubRange<15, 25> range5(20);
        SubRange<10, 20> range6 = range5;
    }
}

void main_function_subrange()
{
    using namespace SubRangeClassic;
    // using namespace SubRangeWithTemplate;
    // using namespace SubRangeWithMetaProgramming;
    test_01_classic();
    // test_02_template();
    // test_03_metaprogramming();
}

// =====================================================================================
// End-of-File
// =====================================================================================
