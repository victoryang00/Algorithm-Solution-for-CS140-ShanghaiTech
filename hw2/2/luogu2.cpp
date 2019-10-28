#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define max(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;
const int MAX = 2e4 + 5;
char      ss[ 1 << 17 ], *A = ss, *B = ss;

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
    int x = *pp & 15;
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
int n, cnt, w, sss, ans;
int fi[ MAX ], dis[ MAX ], fa[ MAX ];
struct hehe {
    int nx, nd, co;
} e[ MAX * 2 ];
void add(int a, int b, int c) {
    e[ ++cnt ] = (hehe){fi[ a ], b, c}, fi[ a ] = cnt;
}
void dfs(int x, int fat) {
    for (int v = fi[ x ]; v; v = e[ v ].nx)
        if (e[ v ].nd != fat) {
            fa[ e[ v ].nd ] = e[ v ].co;
            dfs(e[ v ].nd, x);
            dis[ x ] = max(dis[ e[ v ].nd ] + e[ v ].co, dis[ x ]);
        }
    if (dis[ x ] + fa[ x ] > w)
        ans++, dis[ x ] = 0;
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        int k;
        k = read();
        for (int j = 1; j <= k; j++) {
            int b, c;
            b = read();
            c = read();
            add(i, b, c);
            sss = max(sss, c);
        }
    }
    w = read();
    if (sss >= w) {
        cout << "No solution.";
        return 0;
    }
    dfs(1, 1);
    cout << ans;
    return 0;
}