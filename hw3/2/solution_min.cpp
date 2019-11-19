#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int         N = 5e4 + 10;
typedef long long LL;
int               n, m, l, Max, qu[ N ];
LL                ans[ N ];
struct edge {
    int  x, y, z;
    bool operator<(const edge &rhs) const {
        return z < rhs.z;
    }
};
vector<edge> G[ N ];

struct dat {
    LL   u, v, cur, dis;
    bool operator<(const dat &rhs) const {
        return dis > rhs.dis;
    }
};

priority_queue<dat> q;
void                Dijkstra() {
    while (!q.empty())
        q.pop();
    for (int i = 1; i <= n; i++)
        if (G[ i ].size())
            q.push((dat){G[ i ][ 0 ].x, G[ i ][ 0 ].y, 0, G[ i ][ 0 ].z});
    int num = 0;
    while (!q.empty()) {
        dat x = q.top();
        q.pop();
        ans[ ++num ] = x.dis;
        if (num >= Max)
            break;
        if (x.cur + 1 < G[ x.u ].size())
            q.push((dat){x.u, G[ x.u ][ x.cur + 1 ].y, x.cur + 1,
                         x.dis + G[ x.u ][ x.cur + 1 ].z - G[ x.u ][ x.cur ].z});
        for (int i = 0; i < G[ x.v ].size(); i++) {
            edge e = G[ x.v ][ i ];
            q.push((dat){x.v, e.y, 0, x.dis + e.z});
            break;
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 1; i <= n; i++)
        G[ i ].clear();
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        G[ x ].push_back((edge){x, y, z});
    }
    for (int i = 1; i <= n; i++)
        sort(G[ i ].begin(), G[ i ].end());
    Max = 0;
    for (int i = 1; i <= l; i++)
        scanf("%d", &qu[ i ]), Max = max(Max, qu[ i ]);
    Dijkstra();
    for (int i = 1; i <= l; i++)
        printf("%lld\n", ans[ qu[ i ] ]);
    return 0;
}