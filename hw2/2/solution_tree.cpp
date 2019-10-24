#include <iostream>
#include <time.h>
using namespace std;
const int   buffsize = 1e5;
char        buf[ buffsize ], *pp = buf - 1;
int         readsize = 0, freadsize = 0;
inline void readinit() {
    fread(buf + (((readsize + buffsize - 1) % buffsize >= buffsize / 2 - 1) ? 0 : buffsize / 2), 1,
          buffsize / 2, stdin);
    freadsize += buffsize / 2;
}
inline int read() {
    if (readsize + buffsize / 2 > freadsize)
        readinit();
    while ((++readsize, *++pp) < '-')
        if (pp == buf + buffsize - 1)
            pp = buf - 1;
    register int x = *pp & 15;
    if (pp == buf + buffsize - 1)
        pp = buf - 1;
    while ((++readsize, *++pp) > '-') {
        x = x * 10 + (*pp & 15);
        if (pp == buf + buffsize - 1)
            pp = buf - 1;
    }
    if (pp == buf + buffsize - 1)
        pp = buf - 1;
    return x;
}
template <typename Type> class Node {
public:
    Type  m_element;
    Node *next;
    Node(Type val,Node *p=nullptr){
        this->m_element=val;
        this->next=p;
    };
    ~Node(){};
};

template <typename Type> class List {
public:
    Node<Type> *head;
    Node<Type> *tail;
    int         count;
    List(Node *p=nullptr,Node *t=nullptr){
        this->head=nullptr;
        this->tail=nullptr;
        count=0;
    };
        
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
            return nullptr;
        }
        Type t = m_list->pop();
        return t;
    }
    void enque(Type val) {
        m_list->push_back(val);
    }
    Queue(Type val) {
        m_list = new List<Type>();
    }
    bool is_empty() {
        return m_list->is_empty();
    }
};

