#include <iostream>
using namespace std;
int         s[ 500050 ];
int         t        = 0;
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
void pop() {
    s[ t-- ] = 0;
}
void push(int a) {
    s[ ++t ] = a;
}
long long int sum = 0;
int           main() {
    int n, a;
    n = read();
    for (int i = 1; i <= n; i++) {
        a = read();
        if (t == 0)
            push(a);
        else if (a > s[ t ]) {
            while (t && a > s[ t ]) {
                sum++;
                pop();
            }
            int p = t;
            while (p > 1 && s[ p ] == a) {
                sum++;
                p--;
            }
            if (t > 0)
                sum++;
            push(a);
        } else {
            int p = t;
            while (p > 1 && s[ p ] == a) {
                sum++;
                p--;
            }
            sum++;
            push(a);
        }
    }
    cout << sum << endl;
    return 0;
}