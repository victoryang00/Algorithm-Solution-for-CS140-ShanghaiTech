#include <iostream>
int g_init;
int ans = 0;
using namespace std;

template <class T> class myVector {
public:
    myVector()
        : p(NULL)
        , capacity(0)
        , size(0) {
    }
    ~myVector() {
        if (p != NULL)
            delete[] p;
    }
    myVector(const myVector &v) {
        this->capacity = v.capacity;
        this->size     = v.size;
        this->p        = new T[ this->capacity ];
        memcpy(this->p, v.p, this->size * sizeof(T));
    }
    void print() {
        for (int i = 0; i < this->size; i++)
            cout << this->p[ i ] << " ";
        cout << endl;
    }
    void push_back(T data) {
        if (this->p == NULL) {
            this->capacity = 1;
            this->size     = 0;
            this->p        = new T[ capacity ];
        }
        if (this->size == this->capacity) {
            T *new_p = new T[ this->capacity * 2 ];
            memcpy(new_p, p, this->size * sizeof(T));
            this->capacity *= 2;
            delete[] p;
            p = new_p;
        }
        this->p[ this->size++ ] = data;
    }
    T pop_back() {
        if (this->size > 1) {
            this->p[ this->size - 1 ] = 0;
            this->size--;
        }
        error();
    }
    void insert(int pos, T data) {
        if (pos >= 0 && pos <= this->size) {
            if (this->size == this->capacity) {
                T *new_p = new T[ this->capacity * 2 ];
                memcpy(new_p, this->p, this->size * sizeof(T));
                this->capacity *= 2;
                delete[] p;
                p = new_p;
            }
            for (int i = this->size; i > pos; i--)
                this->p[ size ] = this->p[ size - 1 ];
            this->p[ pos ] = data;
            this->size++;
        }
        error();
    }
    void error() {
        cout << "error";
    }
    T &operator[](int index) {
        if (index >= 0 && index < this->size)
            return this->p[ index ];
        error();
    }
    T &operator=(const myVector &v) {
        if (this->p != NULL) {
            delete[] p;
            this->capacity = 0;
            this->size     = 0;
            this->p        = NULL;
        }
        this->capacity = v.capacity;
        this->size     = v.size;
        this->p        = new T[ this->capacity ];
        memcpy(p, v.p, this->size * sizeof(T));
    }
    void erase(const int &pos) // Erase the element at "pos"..
    {
        for (int i = pos; i < size; i++) {
            p[ i ] = p[ i + 1 ];
        }
        --size;
    }
    int Size() {
        return this->size;
    }
    int Capacity() {
        return this->capacity;
    }
    T * p;
    int capacity;
    int size;
};
template <typename T> class Queue {
public:
    myVector<T> q;
    void        enque(T data) {
        q.insert(0, data);
    }

    T deque() {
        q.pop_back();
    }
};
template <class T> class TreeNode {

public:
    T                        data;
    TreeNode<T> *            m_parent;
    myVector<TreeNode<T> *> *children;
    int                      max_children = 0;

    TreeNode(TreeNode<T> *parent, T data);
    ~TreeNode();
};

template <class T> TreeNode<T>::TreeNode(TreeNode<T> *parent, T decay) {
    data     = decay;
    m_parent = parent;
    children = new myVector<TreeNode<T> *>();
}

template <class T> TreeNode<T>::~TreeNode() {
    delete data;
    for (TreeNode<T> *childNode : children)
        delete childNode;
}

int min_amp(TreeNode<int> *root);

int min_amp(TreeNode<int> *root) {

    for (int i = 0; i < root->children->size; ++i) {
        TreeNode<int> *temp = root->children->pop_back();
        min_amp(temp);
    }

    if (root->m_parent == nullptr) {
        return 0;
    }

    if ((root->max_children + root->data) <= g_init) {
        root->data += root->max_children;
    } else {
        ans++;
        root->max_children = 0;
    }
    if (root->data > root->m_parent->max_children) {
        root->m_parent->max_children = root->data;
    }
}

int main() {
    int  max          = 0;
    bool has_solution = true;
    int  n_nodes, id = 1, n_child, decay;
    cin >> n_nodes;
    TreeNode<int> *         root = new TreeNode<int>(nullptr, 0);
    TreeNode<int> *         curr = root;
    TreeNode<int> *         temp;
    Queue<TreeNode<int> *> *q_in = new Queue<TreeNode<int> *>();
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
            temp = new TreeNode<int>(curr, decay);
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

    if (!has_solution) {
        cout << "No solution.";
    } else {
        cout << ans;
    }

    return 0;
}