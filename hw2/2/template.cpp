#include <iostream>
#include <time.h>
int g_init;
int ans = 0;
using namespace std;

template <typename Type> class Node {
public:
    Type  m_element;
    Node *next;
    Node(Type val)
        : m_element(val)
        , next(nullptr){};
    ~Node(){};
};

template <typename Type> class List {
public:
    Node<Type> *head;
    Node<Type> *tail;
    int         count;
    List()
        : head(nullptr)
        , tail(nullptr)
        , count(0){};
    bool is_empty() {
        return head == nullptr;
    };
    void push_back(Type val) {
        count++;
        if (head != nullptr) {
            tail->next = new Node<Type>(val);
            tail       = tail->next;
        } else {
            head = new Node<Type>(val);
            tail = head;
        }
    };
    void push_front(Type val) {
        count++;
        Node<Type> *temp = head;
        if (head != nullptr) {
            head       = new Node<Type>(val);
            head->next = temp;
        } else {
            head = new Node<Type>(val);
            tail = head;
        }
    };
    Type pop() {
        ;
        Node<Type> *temp = head;
        head             = head->next;
        return temp->m_element;
    };
};

class Tree {
public:
    int           m_decay;
    Tree *        m_parent;
    List<Tree *> *children;
    int           max_child = 0;
    Tree(Tree *parent, int decay) {
        m_decay  = decay;
        m_parent = parent;
        children = new List<Tree *>();
    };
    bool is_leaf() {
        return children->is_empty();
    };
};

template <typename Type> class Queue {
public:
    List<Type> *m_list;
    Type        deque() {
        if (m_list->is_empty()) {
            // cout<<"invalid\n";
            return nullptr;
        }
        Type t = m_list->pop();
        // cout<<"deque:"<<t<<endl;
        return t;
    }
    void enque(Type val) {
        // cout<<"enque:"<<val<<endl;
        m_list->push_back(val);
    }
    Queue() {
        m_list = new List<Type>();
    }
    bool is_empty() {
        return m_list->is_empty();
    }
};
