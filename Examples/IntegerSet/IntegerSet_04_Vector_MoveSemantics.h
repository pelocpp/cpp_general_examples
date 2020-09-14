// ===============================================================================
// IntegerSet: Variant 4 - Modern Approach (std::vector / Move Semantics)
// ===============================================================================

#pragma once

namespace IntegerSetVector_MoveSemantics {

    class IntegerSet
    {
    public:
        // c'tors and d'tor
        IntegerSet() = default;         // default c'tor;
        IntegerSet(std::vector<int> numbers);  // user-defined c'tor
        IntegerSet(const IntegerSet&);  // copy c'tor
        ~IntegerSet() = default;        // d'tor

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
        void swap(IntegerSet& set1, IntegerSet& set2) noexcept; // 'swap idiom'

        // private member data
        std::vector<int> m_set;
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
