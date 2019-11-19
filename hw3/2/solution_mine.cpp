#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define LL long long
using namespace std;
const int INF  = 0x3f3f3f3f;
const int maxn = 2e5 + 50;
int       n, m, k;
LL        ans[ maxn ];
struct edge {
    int to;
    LL  w;
};
vector<edge> g[ maxn ];
bool         cmp(const edge &x, const edge &y) {
    return x.w < y.w;
}
struct node {
    int         u, v;
    int         cur;
    LL          sum;
    friend bool operator<(const node &x, const node &y) {
        return x.sum > y.sum;
    }
};
void solve() {
    for (int i = 1; i <= n; i++)
        sort(g[ i ].begin(), g[ i ].end(), cmp);
    priority_queue<node> q;
    for (int i = 1; i <= n; i++) {
        if (!g[ i ].empty()) {
            q.push(node{i, g[ i ][ 0 ].to, 0, g[ i ][ 0 ].w});
            q.push(node{g[ i ][ 0 ].to, i, 0, g[ i ][ 0 ].w});
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
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        g[ i ].clear();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[ u ].push_back(edge{v, w});
    }
    solve();
    for (int i = 0; i < k; i++)
        printf("%lld\n", ans[ i ]);

    return 0;
}