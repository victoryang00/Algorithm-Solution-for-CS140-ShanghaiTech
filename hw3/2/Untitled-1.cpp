#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define LL long long
using namespace std;
template <typename T> class MiniVector {
private:
    int  size;
    int  capacity;
    T *  ptr;
    void Reserve(int c);

public:
    MiniVector(int = 0);
    T              At(int n);
    T              Front();
    T              Back();
    int            Size();
    bool           Empty();
    void           Push_Back(const T &item);
    void           Pop_Back();
    T              operator[](int n) const;
    MiniVector<T> &operator=(const MiniVector<T> &rightHandSide);
};
template <typename T> MiniVector<T>::MiniVector(int s) {
    size     = s;
    capacity = s + 1;
    ptr      = new T[ capacity ];
    for (int i = 0; i < capacity; i++) {
        ptr[ i ] = T();
    }
}
template <typename T> T MiniVector<T>::At(int n) {
    if (n < 0 || n >= size) {
        throw "Out of Range";
    }
    return ptr[ n ];
}
template <typename T> int MiniVector<T>::Size() {
    return this->size;
}
template <typename T> T MiniVector<T>::Front() {
    if (Empty()) {
        cout << "ERROR: Front element not found" << endl;
        throw "empty";
    }
    return ptr[ 0 ];
}
template <typename T> T MiniVector<T>::Back() {
    if (Empty()) {
        cout << "ERROR: Front element not found" << endl;
        throw "empty";
    }
    return ptr[ size - 1 ];
}
template <typename T> bool MiniVector<T>::Empty() {
    return (size == 0);
}
template <typename T> void MiniVector<T>::Push_Back(const T &item) {
    if (size == capacity) {
        Reserve(capacity * 2);
    }
    ptr[ size ] = item;
    size++;
}
template <typename T> void MiniVector<T>::Pop_Back() {
    if (Empty()) {
        cout << "It is empty" << endl;
        throw "empty";
    }
    ptr[ size - 1 ] = T();
    size--;
}
template <typename T> void MiniVector<T>::Reserve(int cap) {
    T *tempPtr;
    tempPtr = new T[ cap ];

    for (int i = 0; i < size; i++) {
        tempPtr[ i ] = ptr[ i ];
    }
    delete[] ptr;
    ptr = tempPtr;

    capacity = cap;
}
template <typename T> T MiniVector<T>::operator[](int n) const {
    if (n < 0 || n >= size) {
        throw "Out of Range";
    }
    return ptr[ n ];
}
template <typename T> MiniVector<T> &MiniVector<T>::operator=(const MiniVector<T> &rhs) {
    this->size     = rhs.size;
    this->capacity = rhs.capacity;
    this->ptr      = new T[ capacity ];

    for (int i = 0; i < size; i++) {
        this->ptr[ i ] = rhs.ptr[ i ];
    }

    return *this;
}

const int INF  = 0x3f3f3f3f;
const int maxn = 2e5 + 50;
int       n, m, k;
LL        ans[ maxn ];
struct edge {
    int to;
    LL  w;
};
MiniVector<edge> g[ maxn ];
struct node {
    int         u, v;
    int         cur;
    LL          sum;
    friend bool operator<(const node &x, const node &y) {
        return x.sum > y.sum;
    }
};
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[ u ].Push_Back(edge{v, w});
    }
    for (int i = 1; i <= n; i++)
        // sort(g[ i ].begin(), g[ i ].end(), cmp);
        priority_queue<node> q;
    for (int i = 1; i <= n; i++) {
        if (!g[ i ].Empty()) {
            q.push(node{i, g[ i ][ 0 ].to, 0, g[ i ][ 0 ].w});
        }
    }
    for (int i = 1; i <= 50000; i++) {
        int u = q.top().u, v = q.top().v, cur = q.top().cur;
        LL  sum = q.top().sum;
        q.pop();
        ans[ i ] = sum;
        if (!g[ v ].empty())
            q.push(node{v, g[ v ][ 0 ].to, 0, sum + g[ v ][ 0 ].w});
        if (cur + 1 < g[ u ].size())
            q.push(node{u, g[ u ][ cur + 1 ].to, cur + 1,
                        sum - g[ u ][ cur ].w + g[ u ][ cur + 1 ].w});
    }
    for (int i = 0; i < k; i++)
        printf("%lld\n", ans[ i ]);

    return 0;
}