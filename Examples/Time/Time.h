// ===========================================================================
// Time.h
// ===========================================================================

#include <iostream>

class Time
{
private:
    int m_seconds;
    int m_minutes;
    int m_hours;

public:
    // c'tors
    Time();
    Time(int seconds, int minutes, int hours);
    Time(int seconds);  // conversion c'tor
    Time(const char*);  // conversion c'tor

    // getter // setter
    int GetSeconds() const { return m_seconds; };
    int GetMinutes() const { return m_minutes; };
    int GetHours() const { return m_hours; };
    void SetSeconds(int seconds);
    void SetMinutes(int minutes);
    void SetHours(int hours);

    // public interface
    void Reset();
    void Add(const Time&);
    void Sub(const Time&);
    Time Diff(const Time&) const;
    void Increment();
    void Decrement();

    // arithmetic operators
    Time operator+ (const Time&) const;
    Time operator- (const Time&) const;

    // arithmetic-assignment operators
    Time operator+= (const Time&);
    Time operator-= (const Time&);
    Time operator+= (int seconds);
    Time operator-= (int seconds);

    // increment/decrement operators (prefix/postfix version)
    friend Time & operator++ (Time&);           // prefix increment
    friend const Time operator++ (Time&, int); // postfix increment
    friend Time & operator-- (Time&);           // prefix decrement
    friend const Time operator-- (Time&, int); // postfix decrement

    // comparison operators
    friend bool operator== (const Time&, const Time&);
    friend bool operator!= (const Time&, const Time&);
    friend bool operator<= (const Time&, const Time&);
    friend bool operator<  (const Time&, const Time&);
    friend bool operator>= (const Time&, const Time&);
    friend bool operator>  (const Time&, const Time&);

    // conversion operator
    operator int();

    // input / output
    friend std::ostream & operator<< (std::ostream&, const Time&);
    friend std::istream & operator>> (std::istream&, Time&);

private:
    // helper methods
    int TimeToSeconds();
    void SecondsToTime(int seconds);
};

// ===========================================================================
// End-of-File
// ===========================================================================
