class String
{
private:
    char* m_ptr;  // buffer
    int  m_len;   // buffer length

public:
    // c'tors and d'tor
    String ();
    String (const char*);
    String (const String&);
    ~String ();

    // assignment operator
    String& operator= (const String&);

    // public methods
    String ToUpperCase ();
    void Print ();
};
