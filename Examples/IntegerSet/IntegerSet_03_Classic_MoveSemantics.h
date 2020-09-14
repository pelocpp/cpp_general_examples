// ===============================================================================
// IntegerSet: Variant 3 - Classic Approach with Move Semantics
// ===============================================================================

#pragma once

namespace IntegerSetClassic_MoveSemantics {

    class IntegerSet
    {
    public:
        // c'tors and d'tor
        IntegerSet();
        IntegerSet(int elems[], int count);
        IntegerSet(const IntegerSet&);
        ~IntegerSet();

        // move semantics
        IntegerSet(IntegerSet&& set) noexcept;  // move-copy c'tor
        IntegerSet& operator= (IntegerSet&& set) noexcept; // move-assignment

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

        int operator[] (size_t) const; // read-only subscript operator

        // arithmetic-assignment operators
        friend const IntegerSet& operator+= (IntegerSet&, const IntegerSet&);
        friend const IntegerSet& operator-= (IntegerSet&, const IntegerSet&);

        // set theory specific methods
        IntegerSet unionset(const IntegerSet&) const;
        IntegerSet difference(const IntegerSet&) const;
        IntegerSet intersection(const IntegerSet&) const;
        bool isPartial(const IntegerSet&) const;

        // set theory specific operators
        friend IntegerSet operator+ (const IntegerSet&, const IntegerSet&);
        friend IntegerSet operator- (const IntegerSet&, const IntegerSet&);
        friend IntegerSet operator^ (const IntegerSet&, const IntegerSet&);
        friend bool operator<= (const IntegerSet&, const IntegerSet&);

        // output operator
        friend std::ostream& operator<< (std::ostream&, const IntegerSet&);

    private:
        // private helper methods
        void cleanup();
        void moveFrom(IntegerSet& set) noexcept;

        void swap(IntegerSet& set1, IntegerSet& set2) noexcept;  // 'swap idiom'

        // private member data
        int  m_num;  // current number of elements
        int* m_set;  // array of elements
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
