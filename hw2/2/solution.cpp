#include <iostream>
int g_init;
int ans = 0;
using namespace std;

template <class T> class myVector {
public:
    myVector()
        : p(NULL)
        , capacity(0)
        , size(0) //Ĭ�Ϲ��캯��
    {
    }
    myVector(int size) //Ĭ�ϸ�ֵΪ0�Ĺ��캯��
    {
        this->size     = size;
        this->capacity = size;
        this->p        = new T[ capacity ];
        for (int i = 0; i < this->size; i++)
            this->p[ i ] = 0;
    }
    myVector(int size, int data) //�ṩ��ֵ�Ĺ��캯��
    {
        this->size     = size;
        this->capacity = size;
        this->p        = new T[ capacity ];
        for (int i = 0; i < this->size; i++)
            this->p[ i ] = data;
    }
    //�������ṩ����һЩ���ڳ�ʼ���Ĺ��캯��

    //�����������ͷŵ�Ψһ��ָ��
    ~myVector() {
        if (p != NULL)
            delete[] p;
    }
    //�������캯��
    myVector(const myVector &v) {
        this->capacity = v.capacity;
        this->size     = v.size;
        this->p        = new T[ this->capacity ]; //�����ڴ�ռ�
        memcpy(this->p, v.p, this->size * sizeof(T));
    }
    //��������Ԫ��
    void print() {
        for (int i = 0; i < this->size; i++)
            cout << this->p[ i ] << " ";
        cout << endl;
    }
    //����
    void push_back(T data) {
        if (this->p == NULL) {
            this->capacity = 1;
            this->size     = 0;
            this->p        = new T[ capacity ];
        }
        if (this->size == this->capacity) //���ݣ����·����ڴ�ռ�
        {
            T *new_p = new T[ this->capacity * 2 ];
            memcpy(new_p, p, this->size * sizeof(T));
            this->capacity *= 2;
            delete[] p;
            p = new_p;
        }
        this->p[ this->size++ ] = data;
    }
    //ɾ��
    T pop_back() {
        if (this->size > 1) {
            this->p[ this->size - 1 ] = 0;
            this->size--;
        }
        error();
    }

    //ָ��λ��ɾ��(Ԫ�غ���)
    void insert(int pos, T data) {
        if (pos >= 0 && pos <= this->size) {
            if (this->size == this->capacity) //�Ѿ����ˣ�����
            {
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
        cout << "����Խ�磡";
    }
    void clear() {
        this->size = 0;
    }
    //����[]�����
    T &operator[](int index) {
        if (index >= 0 && index < this->size)
            return this->p[ index ];
        error();
    }
    //����=�����
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
    int Size() {
        return this->size;
    }
    int Capacity() {
        return this->capacity;
    }

private:
    T * p;
    int capacity;
    int size;
};

template <typename Type> class Queue {
public:
    myVector<Type> q;
    void           enque(Type d) {
        q.insert(q.end(), d);
    }

    Type deque() {
        q.erase(q.begin());
    }

    int front() {
        return *q.begin();
    }
    Queue() {
        q = new myVector<Type>();
    }
};
template <class T> class TreeNode {

public:
    T                        data;
    TreeNode<T> *            parent;
    myVector<TreeNode<T> *> *children;
    int                      max_children = 0;

    TreeNode(TreeNode<T> *parent, T data);
    ~TreeNode();
};

template <class T>
TreeNode<T>::TreeNode(TreeNode<T> *parent, T data)
    : parent(parent) {
    this->data = new T(data);
}

template <class T> TreeNode<T>::~TreeNode() {
    delete data;
    for (TreeNode<T> *childNode : children)
        delete childNode;
}

int min_amp(TreeNode<int> *root);

int min_amp(TreeNode<int> *root) {

    for (int i = 0; i < root->children->Size; ++i) {
        TreeNode<int> *temp = root->children->pop_back();
        min_amp(temp);
    }

    if (root->parent == nullptr) {
        return 0;
    }

    if ((root->max_children + root->data) <= g_init) {
        root->data += root->max_children;
    } else {
        ans++;
        root->max_children = 0;
        // cout<<"position:"<<root->m_decay<<",maxchild="<<root->max_child<<endl;
    }
    if (root->data > root->parent->max_children) {
        root->parent->max_children = root->data;
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
            temp = new TreeNode(curr, decay);
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