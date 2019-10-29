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
    int   m_element;
    Node *next;
    Node(int val)
        : m_element(val)
        , next(nullptr){};
    ~Node(){};
};

class List {
public:
    Node *head;
    Node *tail;

    List() {
        head = nullptr;
        tail = nullptr;
    };

    void push(int qan, int sid) {
        if (head == nullptr) {
            head              = (Node *)malloc(sizeof(Node));
            head->m_layer.qan = qan;
            head->m_layer.sid = sid;
            head->next        = nullptr;
            head->previous    = nullptr;
            tail              = head;
        } else {
            if (sid == tail->m_layer.sid) {
                tail->m_layer.qan += qan;
            } else {
                tail->next           = (Node *)malloc(sizeof(Node));
                tail->next->previous = tail;
                tail                 = tail->next;
                tail->m_layer.qan    = qan;
                tail->m_layer.sid    = sid;
                tail->next           = nullptr;
            }
        }
    }
    void pop(int rm_qan) {
        while (rm_qan > 0) {

            if (head == nullptr)
                return;

            if (rm_qan < head->m_layer.qan) {

                head->m_layer.qan -= rm_qan;
                rm_qan = 0;
            }
            if (rm_qan >= head->m_layer.qan) {
                rm_qan -= head->m_layer.qan;
                head = head->next;
                if (head == nullptr) {
                    tail = nullptr;
                } else {
                    head->previous = nullptr;
                }
            }
        }
    }
};