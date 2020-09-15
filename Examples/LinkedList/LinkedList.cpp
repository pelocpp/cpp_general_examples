// ===========================================================================
// Linked.cpp // Linked List with std::unique_ptr<>
// ===========================================================================

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

#include <iostream>
#include <memory>
#include <stdexcept>

namespace LinkedListUniquePtr {

    struct Node {
        int m_data;
        std::unique_ptr<Node> m_next;

        Node(int data);
        ~Node();
    };

    class List {

        friend std::ostream& operator<<(std::ostream& os, const List& list);

    public:

        List();
        ~List();

        void addHead(int data);
        bool insertAt(int data, int pos);
        void removeHead();
        int atHead();
        int atTail();
        void reverse();
        void clear();

    private:
        std::unique_ptr<Node> m_head;
        int m_count;
    };

    // ===========================================================================

    Node::Node(int data) : m_data{ data }, m_next{ nullptr } {}
    Node::~Node() {
        std::cout << "d'tor Node [" << m_data << "]" << std::endl;
    }

    // ===========================================================================

    List::List() : m_head{ nullptr }, m_count{ 0 }{}

    List::~List() {
        clear();
        std::cout << "d'tor List " << std::endl;
    }

    void List::addHead(int n) {
        std::unique_ptr<Node> temp{ std::make_unique<Node>(n) };
        if (m_head != nullptr) {
            temp->m_next = std::move(m_head);
            m_head = std::move(temp);
        }
        else {
            m_head = std::move(temp);
        }
        ++m_count;
    }

    bool List::insertAt(int n, int pos) {

        // verify params
        if (pos < 0 || pos > m_count) {
            return false;
        }

        std::unique_ptr<Node> temp{ std::make_unique<Node>(n) };
        if (pos == 0) {
            temp->m_next = std::move(m_head);
            m_head = std::move(temp);
        }
        else {
            Node* current = m_head.get();

            while (pos - 1 > 0) {
                current = current->m_next.get();
                --pos;
            }

            temp->m_next = std::move(current->m_next);
            current->m_next = std::move(temp);
        }

        ++m_count;
        return true;
    }

    void List::removeHead() {
        if (m_head == nullptr) {
            throw std::out_of_range("list empty");
        }

        std::unique_ptr<Node> temp = std::move(m_head);
        m_head = std::move(temp->m_next);
    }

    int List::atHead() {
        if (m_head == nullptr) {
            return -1;  // throw !!!
        }

        return m_head.get()->m_data;
    }


    void List::reverse() {
        List tmp;
        Node* root = m_head.get();
        while (root) {
            tmp.addHead(root->m_data);
            root = root->m_next.get();
        }
        clear();
        m_head = std::move(tmp.m_head);
    }

    void List::clear() {
        while (m_head) {
            m_head = std::move(m_head->m_next);
        }
    }

    std::ostream& operator<<(std::ostream& os, const List& list) {
        Node* m_head = list.m_head.get();
        while (m_head) {
            os << m_head->m_data << ' ';
            m_head = m_head->m_next.get();

        }
        return os;
    }
}

// ===========================================================================

void test_01_linked_list () {

    using namespace LinkedListUniquePtr;

    std::unique_ptr<Node> n0{ std::make_unique<Node>(0) };
    std::unique_ptr<Node> n1{ std::make_unique<Node>(1) };
    std::unique_ptr<Node> n2{ std::make_unique<Node>(2) };

    n1->m_next = std::move(n0);
    n2->m_next = std::move(n1);
}

void test_02_linked_list() {

    using namespace LinkedListUniquePtr;

    List list;
    list.addHead(0);
    list.addHead(1);
    list.addHead(2);
    list.addHead(3);
}

void test_03_linked_list() {

    using namespace LinkedListUniquePtr;

    // demonstrate a stack overflow - due to the recursive nature of the d'tor
    List list;

    const int Max = 10;           // Zum Testen
    // const int Max = 10000;    // Hier kracht es bereits

    for (int i = 0; i < Max; ++i) {
        list.addHead(i);
    }

    std::cout <<
        "Last line of the program. After this, " 
        "the list nodes will be recursively destroyed!\n";
}

void test_04_linked_list() {

    using namespace LinkedListUniquePtr;

    List list;
    std::cout << "The list is empty: " << list << '\n';

    for (int i = 0; i < 10; ++i) {
        list.addHead(i);
    }

    std::cout << "The list with 10 nodes: " << list << std::endl;
    list.clear();
    std::cout << "The list after clean(): " << list << std::endl;
}

void test_05_linked_list() {

    using namespace LinkedListUniquePtr;

    List list;
    list.addHead(1);
    list.addHead(2);
    list.addHead(3);
    list.addHead(4);
    list.addHead(5);

    std::cout << list << std::endl;
    list.removeHead();
    std::cout << list << std::endl;
    list.removeHead();
    std::cout << list << std::endl;
    list.removeHead();
    std::cout << list << std::endl;
    list.removeHead();
    std::cout << list << std::endl;
    list.removeHead();
}

void test_06_linked_list() {

    using namespace LinkedListUniquePtr;

    List list;

    list.addHead(-10);
    std::cout << list << std::endl;

    list.removeHead();
    std::cout << list << std::endl;

    for (int i = 0; i < 10; ++i) {
        list.addHead(i);
    }
    std::cout << list << std::endl;

    list.removeHead();
    list.removeHead();
    list.removeHead();
    std::cout << list << std::endl;

    list.addHead(-20);
    list.addHead(-30);
    std::cout << list << std::endl;

    list.clear();
    std::cout << list << std::endl;

    list.addHead(-1);
    list.addHead(-2);
    std::cout << list << std::endl;
}

void test_10_linked_list() {

    using namespace LinkedListUniquePtr;

    // test insert
    List list;
    list.addHead(1);
    list.addHead(2);
    list.addHead(3);

    std::cout << list << std::endl;
    list.insertAt(10, 0);
    std::cout << list << std::endl;
    list.insertAt(11, 1);
    std::cout << list << std::endl;
    list.insertAt(12, 5);
    std::cout << list << std::endl;
}

void main_linked_list() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    test_01_linked_list();
    test_02_linked_list();
    // test_03_linked_list();
    test_04_linked_list();
    test_05_linked_list();
    test_06_linked_list();
    test_10_linked_list();
    std::cout << "Done\n";
}

// ===========================================================================
// End-of-File
// ===========================================================================
