#include <iostream>
#include <time.h>
using namespace std;
// input 7 2 4 1 2 2 5 1
// output 10
class Node {
public:
    Node(int height)
        : m_height(height)
        , next(nullptr){};
    int   m_height;
    Node *next;
};
class List {
public:
    Node *head;
    Node *tail;
    List()
        : head(nullptr)
        , tail(nullptr){};
    void push_back(int val) {
        if (head != nullptr) {
            tail->next = new Node(val);
            tail       = tail->next;
        } else {
            head = new Node(val);
            tail = head;
        }
    };
    ~List(){};
};

int  look_back(Node *head);
void show_list(Node *head);

int main() {
    List *l = new List();
    int   value, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        l->push_back(value);
    }
    // show_list(l->head);
    // cout<<"reading fin!\n";
    // time_t t=time(NULL);
    int ans = look_back(l->head);
    // cout<<"time: "<<time(NULL)-t<<endl;
    cout << ans;
    return 0;
}

void show_list(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->m_height << endl;
        temp = temp->next;
    }
}
int look_back(Node *head) {
    Node *temp = head;
    int   current_height;
    int   maximum = 0;
    int   count   = 0;
    while (head->next != nullptr) {

        temp           = head->next;
        current_height = head->m_height;
        // add the n and (n+1) th gay be a pair
        count++;
        // cout<<"head: "<<head->m_height<<endl;
        // cout<<"pair"<<" ( "<<current_height<<","<<head->next->m_height<<" )"<<endl;
        maximum = head->next->m_height;
        while (temp->next != nullptr) {
            if (current_height < maximum) {
                temp = temp->next;
                break;
            } else if (temp->next->m_height < maximum) {
                temp = temp->next;
            } else {
                maximum = maximum >= temp->next->m_height ? maximum : temp->next->m_height;
                count++;
                // cout<<"pair"<<" ( "<<current_height<<","<<temp->next->m_height<<" )"<<endl;
                temp = temp->next;
            }
        }
        head = head->next;
    }
    return count;
}
