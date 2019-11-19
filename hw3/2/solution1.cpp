#include <bits/stdc++.h>
#define MP make_pair
#define sz(g) (int)g.size()
#define fi first
#define se second
#define INF 0x3f3f3f3f
using namespace std;
typedef long long      ll;
typedef pair<int, int> pii;
const int              N = 2e5 + 5;
int                    T, n, m, Q;
vector<pii>            g[ N ];
int                    query[ N ];
ll                     res[ N ];
struct node {
    int  from, e;
    ll   dis;
    bool operator<(const node &A) const {
        return dis > A.dis;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m >> Q;
        for (int i = 1; i <= n; i++)
            g[ i ].clear();
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g[ u ].push_back(MP(v, w));
        }
        for (int i = 1; i <= n; i++) {
            sort(g[ i ].begin(), g[ i ].end(), [&](pii A, pii B) { return A.se < B.se; });
        }
        int MAX = 0, cnt = 0;
        for (int i = 1; i <= Q; i++)
            cin >> query[ i ], MAX = max(MAX, query[ i ]);
        priority_queue<node> q;
        for (int i = 1; i <= n; i++) {
            if (sz(g[ i ]))
                q.push(node{i, 0, g[ i ][ 0 ].se});
        }
        while (!q.empty()) {
            node cur = q.top();
            q.pop();
            res[ ++cnt ] = cur.dis;
            if (cnt > MAX)
                break;
            int u = cur.from, e = cur.e;
            if (e + 1 < sz(g[ u ])) {
                q.push(node{u, e + 1, cur.dis - g[ u ][ e ].se + g[ u ][ e + 1 ].se});
            }
            int v = g[ u ][ e ].fi;
            if (sz(g[ v ]))
                q.push(node{v, 0, cur.dis + g[ v ][ 0 ].se});
        }
        for (int i = 1; i <= Q; i++) {
            cout << res[ query[ i ] ] << '\n';
        }
    }
    return 0;