#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define fi first
#define se second
typedef long long     ll;
typedef pair<ll, int> pii;
const int             amn = 5e4 + 5;
vector<pii>           eg[ amn ];
struct node {
    int u, v;
    ll  w;
    node(int uu, int vv, ll ww) {
        u = uu;
        v = vv;
        w = ww;
    }
    bool operator<(const node a) const {
        return w > a.w;
    }
};
priority_queue<node> pq;
int                  n, m, q, u, v, k[ amn ], maxk;
ll                   w, ans[ amn ];
int                  main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i++)
            eg[ i ].clear(); ///初始化vector
        while (pq.size())
            pq.pop(); ///初始化优先队列
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%lld", &u, &v, &w);
            eg[ u ].pb(pii(w, v)); /// pair的first存边权是因为排序时先按first排再按second排
        }
        for (int i = 1; i <= n; i++)
            sort(eg[ i ].begin(), eg[ i ].end()); ///对每个节点的邻接点按边权升序排序
        maxk = 0;
        for (int i = 1; i <= q; i++) {
            scanf("%d", &k[ i ]); ///记录询问顺序，下面离线处理答案
            maxk = max(maxk, k[ i ]); ///记录一个最大的第k小，就要搜索到这里
        }
        for (int i = 1; i <= n; i++)
            if (eg[ i ].size())
                pq.push(node(i, 0, eg[ i ][ 0 ].fi)); ///把每个点边权最小的邻接点加入搜索队列
        int tp = 0;
        while (pq.size()) {
            node cu = pq.top();
            pq.pop();
            ans[ ++tp ] = cu.w; ///记录路径和第tp小的答案
            if (tp >= maxk)
                break; ///知道了最大的第k小的路径就不用搜索了
            if (cu.v + 1 < eg[ cu.u ].size())
                pq.push(node(
                    cu.u, cu.v + 1,
                    cu.w - eg[ cu.u ][ cu.v ].fi +
                        eg[ cu.u ][ cu.v + 1 ]
                            .fi)); ///现在记录过当前点连接当前邻接点的答案了,就搜索当前点不连这个邻接点而是下一个邻接点的情况
            int v = eg[ cu.u ][ cu.v ].se;
            if (eg[ v ].size())
                pq.push(node(
                    v, 0,
                    cu.w +
                        eg[ v ][ 0 ].fi)); ///当前邻接点连接下一个边权最小的当前邻接点的邻接点的情况
        }
        for (int i = 1; i <= q; i++)
            printf("%lld\n", ans[ k[ i ] ]); ///按询问顺序输出答案
    }
}
/**
给n个点和m条条有权边.路径值为路径中的边权和,问第k小条的路径值为多少
考虑BFS,如果路径不止一条能知道路径值最小的路径,就能推出第2小的,由第2小推出第3小,由第k-1小推出第k小
先把边权排序,这样可以从边权最小的开始访问
搜索队列用优先队列可以每次取出路径和最小的,记录下答案,现在记录过当前点连接当前邻接点的答案了,就搜索当前点不连这个邻接点而是下一个邻接点的情况和当前邻接点连接下一个边权最小的当前邻接点的邻接点的情况
最后输出答案
**/