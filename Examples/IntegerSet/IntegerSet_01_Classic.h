// ===============================================================================
// IntegerSet: Variant 1 - Classic Approach (using raw pointer with new / delete)
// ===============================================================================

#pragma once

namespace IntegerSetClassic {

    class IntegerSet
    {
    public:
        // c'tors and d'tor
        IntegerSet();
        IntegerSet(int elems[], int count);
        IntegerSet(const IntegerSet&);
        ~IntegerSet();

    public:
        // getter
        int size() const;
        bool isEmpty() const;

        // public methods
        bool insert(int);
        bool remove(int);
        bool contains(int) const;
        void clear();

        // miscellaneous operators
        IntegerSet& operator= (const IntegerSet&);
        friend bool operator== (const IntegerSet&, const IntegerSet&);
        friend bool operator!= (const IntegerSet&, const IntegerSet&);

        const int operator[] (size_t) const; // read-only subscript operator

        // arithmetic-assignment operators
        friend const IntegerSet& operator+= (IntegerSet&, const IntegerSet&);
        friend const IntegerSet& operator-= (IntegerSet&, const IntegerSet&);

        // set theory specific methods
        IntegerSet unionset(const IntegerSet&) const;
        IntegerSet difference(const IntegerSet&) const;
        IntegerSet intersection (const IntegerSet&) const;
        bool isPartial(const IntegerSet&) const;

        // set theory specific operators
        friend IntegerSet operator+ (const IntegerSet&, const IntegerSet&);
        friend IntegerSet operator- (const IntegerSet&, const IntegerSet&);
        friend IntegerSet operator^ (const IntegerSet&, const IntegerSet&);
        friend bool operator<= (const IntegerSet&, const IntegerSet&);

        // output operator
        friend std::ostream& operator<< (std::ostream&, const IntegerSet&);

    private:
        // private member data
        int  m_num;  // current number of elements
        int* m_set;  // array of elements
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
