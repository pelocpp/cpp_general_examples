// ===============================================================================
// Dummy.h // Dummy Class for Testing Purposes
// ===============================================================================

constexpr bool isVerbose = true;

class Dummy
{
private:
    int m_dummy;

public:
    explicit Dummy() : m_dummy (0){
        if (isVerbose) {
            std::cout << "c'tor Dummy [" << m_dummy << "]" << std::endl;
        }
    }

    explicit Dummy(int dummy) : m_dummy(dummy) {
        if (isVerbose) {
            std::cout << "c'tor Dummy [" << m_dummy << "]" << std::endl;
        }
    }

    // "Big-Three"
    ~Dummy() {
        if (isVerbose) {
            std::cout << "d'tor Dummy [" << m_dummy << "]" << std::endl;
        }
    }

    Dummy(const Dummy& other) {
        m_dummy = other.m_dummy;
        std::cout << "copy-c'tor Dummy [" << m_dummy << "]" << std::endl;
    }

    Dummy& operator=(Dummy const& other) {
        m_dummy = other.m_dummy;
        std::cout << "Dummy::operator=" << std::endl;
        return *this;
    }

    // move Semantics / "Big-Five"
    Dummy(Dummy&& other) noexcept {
        m_dummy = other.m_dummy;  // move ownership to target 
        other.m_dummy = 0;        // reset source (symbolic statement)
        std::cout << "Move c'tor Dummy" << std::endl;
    }

    Dummy& operator=(Dummy&& other) noexcept {

        if (this == &other) {
            return *this;
        }

        m_dummy = other.m_dummy;  // move ownership to target 
        other.m_dummy = 0;        // reset source (symbolic statement)
        std::cout << "Move Dummy::operator=" << std::endl;
        return *this;
    }

    // mimimalistic public interface
    int getValue() {
        return m_dummy;
    }

    void sayHello() { 
        std::cout << "Hello Dummy [" << m_dummy << "]" << std::endl;
    }

    // output
    friend std::ostream& operator<< (std::ostream&, const Dummy&);
};

// ===============================================================================
// End-of-File
// ===============================================================================
