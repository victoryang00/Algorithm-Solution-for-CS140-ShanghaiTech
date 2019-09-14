#include <iostream>
#include <set>
using namespace std;

class Node {
public:
    int   data_;
    Node *next_;

public:
    Node()
        : data_(-1)
        , next_(nullptr) {
    }
};

class List {
public:
    List() {
        this->head_ = new Node();

        this->head_->next_ = nullptr;
        this->size_        = 0;
    };
    void insert(int pos, int value);
    void remove(int pos);
    int  get_reverse_element(int reverse_pos);
    void reverse();

    int  operator[](int i);
    void print();
    ~List();

public:
    Node *head_;
    int   size_;
};

void List::insert(int pos, int value) {
    if (pos < 0 || pos > size_)
        return;

    Node *newnode  = new Node();
    newnode->data_ = value;

    newnode->next_ = nullptr;

    Node *p_curr = head_;
    for (int i = 0; i < pos; i++) {
        p_curr = p_curr->next_;
    }

    newnode->next_ = p_curr->next_;
    p_curr->next_  = newnode;
    size_++;
}

void List::remove(int pos) {
    if (pos < 0 || pos > size_) {
        return;
    }
    Node *p_curr = head_;
    for (int i = 0; i < pos; i++) {
        p_curr = p_curr->next_;
    }
    p_curr->next_ = p_curr->next_->next_;
    size_--;
}

int List::operator[](int i) {
    Node *p_curr = head_;
    int   count  = 0;
    while (count <= i) {
        p_curr = p_curr->next_;
        count++;
    }
    return p_curr->data_;
}

List::~List() {
    while (size_ != 0) {
        Node *p_curr = head_;
        for (int i = 0; i < (size_ - 1); i++) {
            p_curr = p_curr->next_;
        }
        delete p_curr->next_;
        p_curr->next_ = nullptr;
        size_--;
        print();
    }
    delete head_;
}

List compute(int total, int keyNumber) {
    List list1;
    for (int i = 0; i < total; i++) {
        list1.insert();
    }
    int count = 0;

    while ((*circle).getTotal() > 1) {
        count++;
        if (count == keyNumber) {
            count = 0;
            keyNumber--;
            (*circle).deletePeople(people);
        }
        people = (*people).getRight();
    }
    return circle;
}
int main() {
    int total, keyNumber;
    cin >> total >> keyNumber;
    Circle *circle = compute(total, keyNumber);
    cout << (*(*circle).getFirst()).getId() << "\n";
}