#include <iostream>
using namespace std;
#define re register int
const int   MAXSIZE = 1e5 + 5;
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
int       n;
long long m[ MAXSIZE ], k[ MAXSIZE ], sum[ MAXSIZE ];
int       main() {
    read(n);
    for (int i = 0; i <= n; i++) {
        read(m[ i ]);
        cout << "1" << '\n';
    }
    for (int i = 0; i <= n; i++) {
        read(k[ i ]);
        sum[ i ] = 0;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[ j ] <= k[ i ]) {
                sum[ i ] += m[ j ];
                m[ j ] = 0;
            } else {
                m[ j ] -= k[ i ];
                sum[ i ] += k[ i ];
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << sum[ i ] << " ";
    }
    cout << "\n";
}