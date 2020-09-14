// ===============================================================================
// CustomIterator.cpp // Demo Implementierung: Custom Iterator fuer Klasse Range
// ===============================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

/*
 * RangeIterator
 */

template <typename T>
class RangeIterator {
private:
    T m_pos;

public:
    RangeIterator();
    RangeIterator(T position);

    // simple iterator interface
    T operator*() const;
    RangeIterator& operator++();
    bool operator!= (const RangeIterator& other);
    bool operator== (const RangeIterator& other);
};

template <typename T>
RangeIterator<T>::RangeIterator() : RangeIterator<T>(0) {}

template <typename T>
RangeIterator<T>::RangeIterator(T position) : m_pos(position) {}

template <typename T>
T RangeIterator<T>::operator*() const {
    return m_pos;
}

template <typename T>
RangeIterator<T>& RangeIterator<T>::operator++() {
    ++m_pos;
    return *this;
}

template <typename T>
bool RangeIterator<T>::operator== (const RangeIterator& other) {
    return m_pos == other.m_pos;
}

template <typename T>
bool RangeIterator<T>::operator!= (const RangeIterator& other) {
    return  !(*this == other);
}

// ===============================================================================

/*
 * Range
 */

template <typename T, T Low, T High>
class Range {
private:
    T m_low;
    T m_high;

public:
    Range() : m_low(Low), m_high(High) {
        if (std::isgreater<T>(Low, High)) {
            throw std::invalid_argument("Illegal values for Low and High!");
        }
    }

    // getter / setter
    T getLow() { return m_low; }
    T getHigh() { return m_high; }

    // iterator
    RangeIterator<T> begin() const;
    RangeIterator<T> end() const;
};

template <typename T, T Low, T High>
RangeIterator<T> Range<T, Low, High>::begin() const {
    return RangeIterator(m_low);
}

template <typename T, T Low, T High>
RangeIterator<T> Range<T, Low, High>::end() const {
    T end = m_high + 1;
    return RangeIterator(end);
}

// ===============================================================================

/*
 * Range
 */

void test_01_rangeiterator() {
    Range<long, 1, 5> range1;
    std::cout << "From " << range1.getLow() << " until " 
        << range1.getHigh() << std::endl;
    for (long i : range1) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    Range<int, 1, 10> range2;
    std::cout << "From " << range2.getLow() << " until " 
        << range2.getHigh() << std::endl;
    for (int i : range2) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    Range<char, 'A', 'F'> range3;
    std::cout << "From " << range3.getLow() << " until " 
        << range3.getHigh() << std::endl;
    for (char i : range3) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

void test_02_rangeiterator() {
    try {
        Range<long, 20, 10> range;
    }
    catch (std::exception ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
}

void test_03_rangeiterator() {
    Range<long, 1, 100> range;
    auto [min_it, max_it] = 
        std::minmax_element(std::begin(range), std::end(range));
    std::cout << *min_it << " - " << *max_it << std::endl;
}

void main_custom_iterator() {
    test_01_rangeiterator();
    test_02_rangeiterator();
    test_03_rangeiterator();
}

// ===============================================================================
// End-of-File
// ===============================================================================
