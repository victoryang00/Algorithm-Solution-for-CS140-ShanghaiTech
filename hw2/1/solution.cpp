#include <iostream>

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
    n = read();
    while (i < n) {
        value = read();
        list->push_back(value);
        i++;
    }
    int ans = look_back(list->head);
    cout << ans;
    return 0;
}

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