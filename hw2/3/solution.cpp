#include <iostream>
using namespace std;
#define re register int
const int   HASHSIZE = 5;
const int   MAXSIZE  = 3e5 + 5;
const int   NMAX     = 3e3 + 5;
char        ss[ 1 << 17 ], *A = ss, *B = ss;
inline char gc() {
    if (A == B) {
        B = (A = ss) + fread(ss, 1, 1 << 17, stdin);
        if (A == B)
            return EOF;
    }
    return *A++;
};
template <class T> inline void read(T &x) {
    char c;
    re   y = 1;
    while (c = gc(), c < 48 || 57 < c)
        if (c == '-')
            y = -1;
    x = c ^ 48;
    while (c = gc(), 47 < c && c < 58)
        x = (x << 1) + (x << 3) + (c ^ 48);
    x *= y;
}
int list_arr[ MAXSIZE ][ HASHSIZE ];
int key[ NMAX ][ NMAX ];
struct list {
    int  count = -1;
    void push_back(int val, int time) {
        count++;
        list_arr[ count ][ 0 ] = val;
        list_arr[ count ][ 1 ] = time;
    }
    void insert(int index, int val, int time) {
        ++count;
        for (int i = count - 1; i >= index; --i) {
            list_arr[ i + 1 ][ 0 ] = list_arr[ i ][ 0 ];
            list_arr[ i + 1 ][ 1 ] = list_arr[ i ][ 1 ];
        }
        list_arr[ index ][ 0 ] = val;
        list_arr[ index ][ 1 ] = time;
    }
    void remove(int num) {
        while (num > 0) {
            if (list_arr[ count ][ 1 ] >= num) {
                list_arr[ count ][ 1 ] -= num;
                num = -1;
            } else {
                num -= list_arr[ count ][ 1 ];
                list_arr[ count ][ 1 ] = 0;
                list_arr[ count ][ 0 ] = 0;
                count--;
            }
        }
    }
    void erase(int index) {

        for (int i = index; i < count; ++i) {
            list_arr[ i ][ 0 ] = list_arr[ i + 1 ][ 0 ];
            list_arr[ i ][ 1 ] = list_arr[ i + 1 ][ 1 ];
        }
        list_arr[ count ][ 1 ] = 0;
        list_arr[ count ][ 0 ] = 0;
        --count;
    }
    void stack_remove(int index, int result) {
        if (list_arr[ index ][ 1 ] >= list_arr[ index + 1 ][ 1 ]) {
            int temp = list_arr[ index + 1 ][ 1 ];
            list_arr[ index ][ 1 ] -= list_arr[ index + 1 ][ 1 ];
            this->erase(index + 1);
            this->insert(index + 1, result, temp);
        } else {
            int temp = list_arr[ index ][ 1 ];
            list_arr[ index + 1 ][ 1 ] -= list_arr[ index ][ 1 ];
            this->erase(index);
            this->insert(index + 1, result, temp);
        }
    }
    int sum() {
        int sum = 0;
        for (int i = 0; i < count + 100000; i++) {
            sum += list_arr[ i ][ 1 ];
        }
        return sum;
    }
    int get_val(int index) {
        return list_arr[ index ][ 0 ];
    }
};

int main() {
    int n, m, k;
    read(n);
    read(m);
    read(k);
    int num1;
    int num2;
    for (int i = 0; i < m; ++i) {
        int num3;
        read(num1);
        read(num2);
        read(num3);
        num1 += 1;
        num2 += 1;
        num3 += 1;
        key[ num2 ][ num1 ] = num3;
        key[ num1 ][ num2 ] = num3;
    }
    list opt;
    for (int i = 0; i < k; ++i) {
        int val1, val2;
        read(val1);
        read(val2);
        val1 += 1;
        if (val1 == 0) {
            opt.remove(val2);
        } else {
            opt.push_back(val1, val2);
        }
    }

    for (int i = 0; i < opt.count; ++i) {
        if (key[ opt.get_val(i) ][ opt.get_val(i + 1) ] > 0) {
            opt.stack_remove(i, key[ opt.get_val(i) ][ opt.get_val(i + 1) ]);
        }
    }
    cout << opt.sum() << "\n";
}