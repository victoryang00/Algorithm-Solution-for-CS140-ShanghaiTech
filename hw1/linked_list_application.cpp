#include <iostream>
#include <set>
#include <stdio.h>
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
        this->head_        = new Node();
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

int List::get_reverse_element(int reverse_pos) {
    int   pos    = size_ - reverse_pos;
    Node *p_curr = head_;
    for (int i = 0; i < pos; i++) {
        p_curr = p_curr->next_;
    }
    return p_curr->data_;
}

void List::reverse() {

    Node *p_curr = head_->next_;
    Node *p_prev = nullptr;
    while (p_curr != nullptr) {
        Node *p_next = p_curr->next_;
        if (p_next == nullptr)
            if (p_curr->next_ == nullptr) {
                head_->next_ = p_curr;
            }
        p_curr->next_ = p_prev;
        p_prev        = p_curr;
        p_curr        = p_next;
    }
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
void List::print() {
    if (size_ == 0) {
        cout << "size = 0" << endl;
        return;
    }

    Node *p_curr = head_->next_;
    while (p_curr != nullptr) {
        cout << p_curr->data_ << " ";
        p_curr = p_curr->next_;
    }
    cout << endl;
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
    cout << "delete!" << endl;
}

void mergeLists(List &list3, List &list4, List &list34) {
    Node *p_curr3  = list3.head_->next_;
    Node *p_curr4  = list4.head_->next_;
    Node *p_curr34 = list34.head_->next_;
    int   location = 0;
    while ((p_curr3 != nullptr) || (p_curr4 != nullptr)) {
        if ((p_curr3 != nullptr) && (p_curr4 != nullptr)) {
            if (p_curr3->data_ < p_curr4->data_) {
                list34.insert(location, p_curr3->data_);
                location++;
                list34.insert(location, p_curr4->data_);
                location++;
            } else {
                list34.insert(location, p_curr4->data_);
                location++;
                list34.insert(location, p_curr3->data_);
                location++;
            }
            p_curr3 = p_curr3->next_;
            p_curr4 = p_curr4->next_;
        } else if ((p_curr3 != nullptr) && (p_curr4 == nullptr)) {
            list34.insert(location, p_curr3->data_);
            location++;
            p_curr3 = p_curr3->next_;
        } else if ((p_curr3 == nullptr) && (p_curr4 != nullptr)) {
            list34.insert(location, p_curr4->data_);
            location++;
            p_curr4 = p_curr4->next_;
        }
    }
}

int main() {
    List list1;

    for (int i = 0; i < 15; i++) {
        list1.insert(i, i);
    }

    list1.remove(10);
    list1.remove(5);

    list1.print();
    list1.reverse();
    list1.print();

    for (int i = 1; i < 4; i++) {
        cout << "倒数第" << i << "个元素是：" << list1.get_reverse_element(i) << endl;
    }
    list1.insert(2, 9999);

    for (int i = list1.size_ - 1; i >= 0; i--) {
        cout << list1[ i ] << " ";
    }
    cout << endl;
    List list2;
    list2.insert(0, 10);
    list2.insert(1, 20);
    list2.insert(2, 30);
    list2.print();
    int size2 = list2.size_;

    List list3, list4;
    for (int i = 0; i < 5; i++) {
        list3.insert(i, 2 * i);
        list4.insert(i, 2 * i + 1);
    }
    list4.insert(5, 12);
    list4.insert(6, 21);
    list3.print();
    list4.print();

    List list34;
    mergeLists(list3, list4, list34);
    list34.print();

    return 1;
}