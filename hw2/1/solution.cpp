#include <iostream>
// #include <stack>
using namespace std;

// void showstack(stack<int> s) {
// while (!s.empty()) {
// cout << '\t' << s.top();
// s.pop();
// }
// cout << '\n';
// }
class Node {
public:
    int   data;
    Node *next;

    Node(int da = 0, Node *p = nullptr) {
        this->data = da;
        this->next = p;
    }
};
class List {
public:
    Node *head, *tail;
    List() {
        head = tail = nullptr;
    };
    ~List() {
        delete head;
        delete tail;
    };
    void push_back(int da) {
        if (head != nullptr) {
            tail->next = new Node(da);
            tail       = tail->next;
        } else {
            head = new Node(da);
            tail = head;
        }
    };
};
int look_back(Node *head);
int main() {
    List *list = new List();
    int   value, n, i = 0;
    cin >> n;
    while (i < n) {
        cin >> value;
        list->push_back(value);
        i++;
    }
    int ans = look_back(list->head);
    cout << ans;
    return 0;
}
// int main() {
//     stack<int> s;
//     int        k, *m, count;
//     cin >> k;
//     if (k == 0)
//         return 0;
//     for (int i = 0; i < k; ++i) {
//         cin >> m[ i ];
//     }
//     s.push(m[ 0 ]);
//     for (int i = 0; i < k; ++i) {
//         if (m[ i ] <= s.top()) {
//             s.push(m[ i ]);
//             count++;
//         } else {
//             while (!s.empty()) {
//                 if (m[ i ] > s.top()) {
//                     s.pop();
//                     count++;
//                 } else {
//                     break;
//                 }
//             }
//             if (s.empty()) {
//                 count++;
//             }
//             s.push(m[ i ]);
//         }
//     }

//     return 0;
// }
int look_back(Node *head) {
    Node *p = head;
    int   curr, max = 0, count = 0;
    for (; (head->next != nullptr); head = head->next) {
        p    = head->next;
        curr = head->data;
        count++;
        max = head->next->data;
        for (; p->next != nullptr; p = p->next) {
            if (curr < max) {
                break;
            } else if (p->next->data >= max) {
                max = max >= p->next->data ? max : p->next->data;
                count++;
            }
        }
    }
    return count;
};