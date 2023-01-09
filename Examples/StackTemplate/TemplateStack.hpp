// ===============================================================================
// TemplateStack.h // Template based Stack
// ===============================================================================

namespace TemplateStack {

    template<typename T, int Max = 10>
    class Stack {
    private:
        int m_index;    // stack pointer 
        T m_data[Max];  // data

    public:
        Stack();
        virtual ~Stack();

        // using exception handling in case of overflow / underflow
        bool push(const T&);
        bool push(T&&);
        T pop();

        // indicating overflow / underflow with return value
        bool pushEx(const T&);
        bool pushEx(T&&);
        bool popEx(T&);

        T top();

        int size() const noexcept;  //  maximum stack size
        int count() const noexcept; // number of elements
        bool isEmpty() const noexcept;
        bool isFull() const noexcept;
    };

    template<typename T, int Max>
    Stack<T, Max>::Stack() : m_index(0) {
        std::cout << "c'tor Stack()" << std::endl;
        std::fill(m_data, m_data + Max, T{});
    }

    template<typename T, int Max>
    Stack<T, Max>::~Stack() {
        std::cout << "d'tor Stack()" << std::endl;
    }

    template<typename T, int Max>
    bool Stack<T, Max>::push(const T& elem) {

        if (m_index >= Max) {
            throw std::out_of_range("stack is full");
        }

        m_data[m_index] = elem;
        ++m_index;
        return true;
    }

    template<typename T, int Max>
    bool Stack<T, Max>::push(T&& elem) {
        if (m_index >= Max) {
            throw std::out_of_range("stack is full");
        }

        m_data[m_index] = std::move(elem);
        ++m_index;
        return true;
    }

    template<typename T, int Max>
    bool Stack<T, Max>::pushEx(const T& elem) {
        bool succeeded = false;
        if (m_index < Max) {
            m_data[m_index] = elem;
            ++m_index;
            succeeded = true;
        }
        return succeeded;
    }

    template<typename T, int Max>
    bool Stack<T, Max>::pushEx(T&& elem) {
        bool succeeded = false;
        if (m_index < Max) {
            m_data[m_index] = std::move(elem);
            ++m_index;
            succeeded = true;
        }
        return succeeded;
    }

    template<typename T, int Max>
    bool Stack<T, Max>::popEx(T& elem) {
        bool succeeded = false;
        if (m_index > 0) {
            --m_index;
            elem = std::move(m_data[m_index]);
            succeeded = true;
        }
        return succeeded;
    }

    template<typename T, int Max>
    T Stack<T, Max>::pop() {

        // is stack empty
        if (m_index == 0) {
            throw std::out_of_range("stack is empty");
        }

        --m_index;
        return std::move(m_data[m_index]);
    }

    template<typename T, int Max>
    T Stack<T, Max>::top() {

        // is stack empty
        if (m_index == 0) {
            throw std::out_of_range("stack is empty");
        }

        int tmp = m_index - 1;
        T elem = m_data[tmp];
        return elem;
    }

    template<typename T, int Max>
    int Stack<T, Max>::size() const noexcept {
        return Max;
    }

    template<typename T, int Max>
    int Stack<T, Max>::count() const noexcept {
        return m_index;
    }

    template<typename T, int Max>
    bool Stack<T, Max>::isEmpty() const noexcept {
        return m_index == 0;
    }

    template<typename T, int Max>
    bool Stack<T, Max>::isFull() const noexcept {
        return m_index == Max;
    }
}

// ===============================================================================
// End-of-File
// ===============================================================================
