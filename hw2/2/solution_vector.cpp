#include <iostream>
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
    void pop_back() {
        if (this->size > 1) {
            this->p[ this->size - 1 ] = 0;
            this->size--;
        }
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
        // error();
    }
    void clear() {
        this->size = 0;
    }
    //����[]�����
    T &operator[](int index) {
        if (index >= 0 && index < this->size)
            return this->p[ index ];
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

class TreeNode {
private:
    int               m_decay;
    int               max_child = 0;
    TreeNode *        m_parent;
    List<TreeNode *> *children;

public:
    TreeNode(TreeNode *parent, int decay) {
        m_decay  = decay;
        m_parent = parent;
        children = new List<TreeNode *>();
    };
    ~TreeNode(){};
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

int min_amp(TreeNode<int> *root) {

    for (int i = 0; i < root->children->count; ++i) {
        TreeNode<int> *temp = root->children->pop();
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