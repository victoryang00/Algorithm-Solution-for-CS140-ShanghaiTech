#include <iostream>
int g_init;
int ans = 0;
using namespace std;
size_t nearest_power_of_2(size_t n) // Return the nearest( and strictly greater than ) number to "n"
                                    // which is a power of 2..
{
    int count = 0;
    while (n) {
        n >>= 1;
        count++;
    }
    return 1ULL << count;
}
template <typename T> class myVector {
public:
    T *    vector_pointer; //  A pointer pointing to the start of the dynamic array...
    size_t vector_size, vector_capacity;

    myVector()
        : vector_pointer(NULL)
        , vector_size(0)
        , vector_capacity(0) {
    } // Default Constructor

    myVector(const myVector &other)
        : vector_pointer(NULL)
        , vector_size(0)
        , vector_capacity(0) // Copy Constructor
    {
        vector_pointer = new T[ other.capacity() ];
        memcpy(vector_pointer, &other[ 0 ], sizeof(T) * other.size());
        vector_size     = other.vector_size;
        vector_capacity = other.vector_capacity;
    }

    ~myVector() // Destructor
    {
        delete[] vector_pointer;
    }

    myVector &operator=(myVector other) // Assignment operator
    {
        swap(*this, other);
        return *this;
    }

    void resize(const size_t &newsize) // Change the size of the vector exactly to "newsize"..
    {
        if (newsize < vector_size) {
            T *temp = new T[ newsize ];
            memcpy(temp, vector_pointer, sizeof(T) * newsize);
            delete[] vector_pointer;
            vector_pointer = temp;
        } else if (newsize > vector_capacity) {
            reserve(newsize);
        }
        vector_size = newsize;
    }

    void reserve(size_t newcapacity) // Change the capacity of the vector to be at least equal to
                                     // "newcapacity"
    {
        newcapacity = nearest_power_of_2(newcapacity); // Keep the capacity of the vector as a power
                                                       // of 2 to avoid space wastage..
        if (newcapacity > vector_capacity) {
            T *temp = new T[ newcapacity ];
            memcpy(temp, vector_pointer, sizeof(T) * vector_capacity);
            delete[] vector_pointer;
            vector_pointer  = temp;
            vector_capacity = newcapacity;
        }
    }

    void push_back(const T &val) // Add a new element of value "val" at the end of the vector..
    {
        if (vector_capacity <= vector_size)
            reserve(vector_capacity);
        vector_pointer[ vector_size++ ] = val;
    }

    T pop_back() // Remove the last element of the vector..
    {
        if (vector_size)
            --vector_size;
    } //  Doesn't actually deallocate the element block (for performance)..

    size_t size() const {
        return vector_size;
    }

    size_t capacity() const {
        return vector_capacity;
    }

    T &operator[](const size_t &pos) {
        return vector_pointer[ pos ];
    }

    const T &operator[](const size_t &pos) const {
        return vector_pointer[ pos ];
    }

    bool empty() const {
        return vector_size == 0;
    }

    T &at(const size_t
              &pos) // Same as the "[]" operator, but this one checks for out-of-bound exceptions..
    {
        if (pos >= vector_size)
            throw std::out_of_range("");
        else
            return vector_pointer[ pos ];
    }

    const T &at(const size_t &pos) const {
        if (pos >= vector_size)
            throw std::out_of_range("");
        else
            return vector_pointer[ pos ];
    }

    void erase(const size_t &pos) // Erase the element at "pos"..
    {
        for (size_t i = pos; i < vector_size - 1; i++) {
            vector_pointer[ i ] = vector_pointer[ i + 1 ]; //  Shift all the elements one step left,
                                                           //  beginning from "pos+1"
        }
        --vector_size;
    }
    void erase(const size_t &pos1, const size_t &pos2) // Erase the elements in range [pos1,pos2)..
    {
        for (size_t i = pos1; i < vector_size - (pos2 - pos1); i++) {
            vector_pointer[ i ] =
                vector_pointer[ i + pos2 - pos1 ]; // Shift all the elements (pos2-pos1) steps left,
                                                   // beginning from "pos2"
        }
        vector_size -= pos2 - pos1;
    }

    void insert(const size_t &pos, const T &val) // Insert 1 element of value "val" at "pos"..
    {
        if (vector_capacity <=
            vector_size) // Create some space if it doesn't have enough to take another element..
            reserve(vector_size);
        vector_size++;
        for (size_t i = vector_size - 1; i > pos;
             i--) //  Shift all the elements one step towards right, beginning from "pos"+1..
        {
            vector_pointer[ i ] = vector_pointer[ i - 1 ];
        }
        vector_pointer[ pos ] = val;
    }

    void insert(const size_t &pos, const size_t &n,
                const T &val) // Insert "n" elements of value "val", beginning from "pos"..
    {
        if (vector_size < n + vector_capacity)
            reserve(vector_size + n); //  Create space for atleast "n" elements...
        vector_size += n;
        for (size_t i = vector_size - 1; i >= pos + n;
             i--) //  Shift all the elements "n" step towards right, beginning from "pos"+1..
        {
            vector_pointer[ i ] = vector_pointer[ i - n ];
        }
        for (size_t i = pos; i < pos + n; i++) // Change all the elements in [pos,pos+n) to "val"..
        {
            vector_pointer[ i ] = val;
        }
    }

    void clear() {
        vector_size = 0;
    } // Again, doesn't actually deallocate (for performance)..

    friend void swap(myVector &a, myVector &b) // Copy and Swap Idiom ...
    {
        using std::swap;
        swap(a.vector_size, b.vector_size);
        swap(a.vector_capacity, b.vector_capacity);
        swap(a.vector_pointer, b.vector_pointer);
    }
};

template <typename T>
std::ostream &operator<<(
    std::ostream &     out,
    const myVector<T> &a) // Overloaded output operator to display the contents of a vector..
{
    for (size_t i = 0; i < a.size(); i++) {
        std::cout << a[ i ] << " ";
    }
    return out;
}
template <typename T> class Queue {
public:
    myVector<T> q;
    void        enque(T d) {
        q.push_back(d);
    }

    T deque() {
        q.erase(0);
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

    for (int i = 0; i < root->children->vector_size; ++i) {
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
        // cout<<"position:"<<root->m_decay<<",maxchild="<<root->max_child<<endl;
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