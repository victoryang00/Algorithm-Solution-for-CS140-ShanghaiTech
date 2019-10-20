

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

template <typename Type> class Stack {
public:
    List<Type> *m_list;
    Type        pop() {
        if (m_list->is_empty()) {
            // cout<<"invalid\n";
            return nullptr;
        }
        Type t = m_list->pop();
        return t;
    }
    void push(Type val) {
        m_list->push_front(val);
    }
    Stack() {
        m_list = new List<Type>();
    }
    bool is_empty() {
        return m_list->is_empty();
    }
};

template <typename Type> void show_list(Node<Type> *head);
int                           min_amp(Tree *root);

template <typename Type> void show_list(Node<Type> *head) {
    Node<Type> *temp = head;
    if (temp == nullptr)
        cout << "null";
    while (temp != nullptr) {
        cout << temp->m_element << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int min_amp(Tree *root) {

    for (int i = 0; i < root->children->count; ++i) {
        Tree *temp = root->children->pop();
        min_amp(temp);
    }

    if (root->m_parent == nullptr) {
        return 0;
    }

    if ((root->max_child + root->m_decay) <= g_init) {
        root->m_decay += root->max_child;
    } else {
        ans++;
        root->max_child = 0;
        // cout<<"position:"<<root->m_decay<<",maxchild="<<root->max_child<<endl;
    }
    if (root->m_decay > root->m_parent->max_child) {
        root->m_parent->max_child = root->m_decay;
    }
}
int main() {
    int  max          = 0;
    bool has_solution = true;
    int  n_nodes, id = 1, n_child, decay;
    cin >> n_nodes;
    Tree *         root = new Tree(nullptr, 0);
    Tree *         curr = root;
    Tree *         temp;
    Queue<Tree *> *q_in = new Queue<Tree *>();
    // construct the tree
    // first read the number of the nodes
    for (int i = 0; i < n_nodes; ++i) {
        cin >> n_child;
        for (int j = 0; j < n_child; ++j) {
            cin >> id >> decay;
            // cout<<"id= "<<id<<" deacy= "<<decay<<endl;
            if (decay > max) {
                max = decay;
            }
            temp = new Tree(curr, decay);
            curr->children->push_back(temp);
            q_in->enque(temp);
        }
        // show_list(q_in->m_list->head);
        curr = q_in->deque();
    }
    //
    cin >> g_init;
    min_amp(root);

    if (max > g_init) {
        has_solution = false;
    }

    // cout<<"power:"<<init<<endl;

    // show_list(root->children->head);

    // cout<<"\n\nstart...\n";

    if (!has_solution) {
        cout << "No solution.";
    } else {
        cout << ans;
    }

    return 0;
}