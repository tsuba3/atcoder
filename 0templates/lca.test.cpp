// Test for lca.cpp
// ABC014 D https://atcoder.jp/contests/abc014/tasks/abc014_4
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;
using vi = vector<int>;
using vl = vector<int64>;
using pii = pair<int, int>;
using pll = pair<int64, int64>;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define print(x) cout << (x) << '\n'
#define print2(x, y) cout << (x) << ' ' << (y) << '\n'
#define print3(x, y, z) cout << (x) << ' ' << (y) << ' ' << (z) << '\n'
#define printn(v) rep(i, (v).size() - 1) cout << (v)[i] << ' '; cout << (v)[n - 1] << '\n';
#define debug(x) cerr << #x << ": " << (x) << '\n'
#define debug2(x, y) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'
#define dbg(v) for (size_t _ = 0; _ < v.size(); ++_){cerr << #v << "[" << _ << "] : " << v[_] << '\n';}
// constant
const int INF = (1<<30) - 1;
const int64 INF64 = (1LL<<62) - 1;
// begin of lca

class LCA {
public:
    // depth[i]: distance between node i and node 0
    vector<int> depth;
    // parent[i][j]: (1 << i)th parent of node j if exists otherwise -1
    vector<vector<int>> parent2;

    LCA(const vector<vector<int>> &vec, const int root = 0) {
        depth.resize(vec.size(), -1);
        parent2.resize(1 + 8 * sizeof(int) - __builtin_clz(vec.size()));
        rep(i, parent2.size()) parent2[i].resize(vec.size(), -1);
        stack<int> dfs;
        dfs.push(root);
        depth[root] = 0;
        while (!dfs.empty()) {
            int i = dfs.top();
            dfs.pop();
            for (int j : vec[i]) if (depth[j] == -1) {
                depth[j] = depth[i] + 1;
                parent2[0][j] = i;
                dfs.push(j);
            }
        }
        rep(pi, parent2.size() - 1) {
            rep(i, vec.size()) parent2[pi + 1][i] = parent2[pi][parent2[pi][i]];
        }
    }

    int parent(int i, int n = 1) const {
        for (int pi = 0; n; ++pi, n >>= 1) if (n & 1) i = parent2[pi][i];
        return i;
    }

    int find(int a, int b) const {
        if (a == b) return a;
        int da = depth[a], db = depth[b];
        if (da > db)
            a = parent(a, da - db);
        else if (db > da)
            b = parent(b, db - da);
        if (a == b) return a;
        for (int p = (8 * sizeof(int) - __builtin_clz(min(da, db))); p >= 0; --p)
            if (parent2[p][a] != parent2[p][b]) a = parent2[p][a], b = parent2[p][b];
        return parent2[0][a];
    }
};

// end of lca

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector<vector<int>> v(n + 1);
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    LCA lca(v, 1);

    cin >> q;
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        print(1 + lca.depth[a] + lca.depth[b] - 2 * lca.depth[lca.find(a, b)]);
    }
}

