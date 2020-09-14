// ===============================================================================
// IntegerSet: Variant 1 - Classic Approach (using raw pointer with new / delete)
// ===============================================================================

#include <iostream>

#include "IntegerSet_01_Classic.h"

namespace IntegerSetClassic {

    // c'tors and d'tor
    IntegerSet::IntegerSet() {
        // empty buffer
        m_num = 0;
        m_set = nullptr;
    }

    IntegerSet::IntegerSet(int elems[], int count) {
        // empty buffer
        m_num = 0;
        m_set = nullptr;

        for (int i = 0; i < count; i++)
            insert(elems[i]);
    }

    IntegerSet::IntegerSet(const IntegerSet& set) {

        // allocate buffer
        m_num = set.m_num;
        m_set = new int[m_num];

        // copy object
        for (int i = 0; i < m_num; i++)
            m_set[i] = set.m_set[i];
    }

    IntegerSet::~IntegerSet() {
        delete[] m_set;
    }

    // getter
    int IntegerSet::size() const {
        return m_num;
    }

    bool IntegerSet::isEmpty() const {
        return m_num == 0;
    }

    // public methods
    bool IntegerSet::contains(int n) const {

        // search element
        for (int i = 0; i < m_num; i++)
            if (m_set[i] == n)
                return true;

        return false;
    }

    bool IntegerSet::insert(int n) {

        // element already exists
        if (contains(n))
            return false;

        // allocate new buffer
        int* tmp = new int[m_num + 1];

        // copy old buffer into new one
        for (int i = 0; i < m_num; i++)
            tmp[i] = m_set[i];

        // insert new element at end of buffer
        tmp[m_num] = n;

        // switch to new buffer
        delete[] m_set;
        m_set = tmp;
        m_num++;

        return true;
    }

    bool IntegerSet::remove(int n) {

        // element already exists
        if (!contains(n))
            return false;

        // allocate new buffer
        int* tmp = new int[m_num - 1];

        // copy old buffer into new one
        for (int i = 0, k = 0; i < m_num; i++) {
            if (m_set[i] == n)
                continue;

            tmp[k] = m_set[i];
            k++;
        }

        // switch to new buffer
        delete[] m_set;
        m_set = tmp;
        m_num--;

        return true;
    }

    void IntegerSet::clear() {

        delete[] m_set;

        m_num = 0;
        m_set = nullptr;
    }

    // operators
    IntegerSet& IntegerSet::operator= (const IntegerSet& set) {

        // prevent self-assignment
        if (this == &set)
            return *this;

        // delete old buffer
        delete[] m_set;

        // allocate a new buffer
        m_num = set.m_num;
        m_set = new int[m_num];

        // copy buffer
        for (int i = 0; i < m_num; i++)
            m_set[i] = set.m_set[i];

        return *this;
    }

    bool operator== (const IntegerSet& lhs, const IntegerSet& rhs) {

        // compare sizes
        if (lhs.m_num != rhs.m_num)
            return false;

        // compare both sets element per element
        for (int i = 0; i < lhs.m_num; i++)
        {
            if (rhs.contains(lhs.m_set[i]))
                continue;

            return false;
        }

        return true;
    }

    bool operator!= (const IntegerSet& lhs, const IntegerSet& rhs) {
        return !(lhs == rhs);
    }

    const int IntegerSet::operator[] (size_t n) const {

        // check parameter
        if (n < 0)
            return -1;
        if (n >= static_cast<size_t> (m_num))
            return -1;

        return m_set[n];
    }

    // arithmetic-assignment operators
    const IntegerSet& operator+= (IntegerSet& lhs, const IntegerSet& rhs) {

        for (int i = 0; i < rhs.m_num; i++)
            lhs.insert(rhs.m_set[i]);

        return lhs;
    }

    const IntegerSet& operator-= (IntegerSet& lhs, const IntegerSet& rhs) {

        for (int i = 0; i < rhs.m_num; i++)
            lhs.remove(rhs.m_set[i]);

        return lhs;
    }

    // set theory specific methods
    IntegerSet IntegerSet::unionset(const IntegerSet& rhs) const {
        IntegerSet set(*this);
        for (int i = 0; i < rhs.m_num; i++)
            set.insert(rhs.m_set[i]);

        return set;
    }

    IntegerSet IntegerSet::difference(const IntegerSet& rhs) const {
        IntegerSet set(*this);
        for (int i = 0; i < rhs.m_num; i++)
            set.remove(rhs.m_set[i]);

        return set;
    }

    IntegerSet IntegerSet::intersection(const IntegerSet& rhs) const {
        IntegerSet set;
        for (int i = 0; i < m_num; i++) {
            int n = m_set[i];
            if (rhs.contains(n))
                set.insert(n);
        }
        return set;
    }

    bool IntegerSet::isPartial(const IntegerSet& rhs) const {
        // compare both sets element per element
        for (int i = 0; i < m_num; i++) {
            int n = m_set[i];
            if (!rhs.contains(n))
                return false;
        }

        return true;
    }

    // set theory specific operators
    IntegerSet operator+ (const IntegerSet& lhs, const IntegerSet& rhs) {
        return lhs.unionset(rhs);
    }

    IntegerSet operator- (const IntegerSet& lhs, const IntegerSet& rhs) {
        return lhs.difference(rhs);
    }

    IntegerSet operator^ (const IntegerSet& lhs, const IntegerSet& rhs) {
        return lhs.intersection(rhs);
    }

    bool operator<= (const IntegerSet& lhs, const IntegerSet& rhs) {
        return lhs.isPartial(rhs);
    }

    // output operator
    std::ostream& operator<< (std::ostream& os, const IntegerSet& set) {
        os << "{";
        for (int i = 0; i < set.m_num; i++) {
            os << set.m_set[i];
            if (i < set.m_num - 1)
                os << ',';
        }
        os << "} [" << set.m_num << "]";

        return os;
    }
}

// ===============================================================================
// End-of-File
// ===============================================================================
