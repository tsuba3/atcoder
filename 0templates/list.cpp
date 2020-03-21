#include "bits/stdc++.h"
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

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

template<typename T> T gcd(T a, T b) {
    if (a < b) return gcd(b, a);
    T r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

// End of template.

/*
 * Array of linked list. N is max size of array. M is max total size of linked list.
 * An instance must be global variable to zero fill arrays.
*/
template<typename T, int N, int M>
class List {
    int k = 0;
public:
    int head[N];
    pair<int, T> nodes[M];
    class ListNode {
        List<T, N, M>& list;
        int i;
        int pointer;
    public:
        ListNode(List<T, N, M>& list, int i, int pointer = -1): list(list) {
            this->i = i, this->pointer = pointer;
        }
        void push_back(T x) {
            list.nodes[++list.k].first = list.head[i];
            list.head[i] = list.k;
            list.nodes[list.k].second = x;
        }
        T& operator *() { return list.nodes[pointer].second; }
        bool operator ==(ListNode& other) { return pointer == other.pointer; }
        bool operator !=(ListNode& other) { return !pointer == other.pointer; }
        void operator ++() { pointer = list.nodes[pointer].first; }
        ListNode&& begin() {
            return ListNode(list, i, list.head[i]);
        }
        ListNode&& end() {
            return ListNode(list, i, -1);
        }
    };
    ListNode operator[](int i) {
        return ListNode(*this, i, head[i]);
    }
};

List<int, 100100, 200200> l;
// begin of lca

class LCA {
public:
    // depth[i]: distance between node i and node 0
    vector<int> depth;
    // parent[i][j]: (1 << i)th parent of node j if exists otherwise -1
    vector<vector<int>> parent2;

    template<typename T>
    LCA(const T& vec, int size, const int root = 0) {
        depth.resize(size, -1);
        parent2.resize(1 + 8 * sizeof(int) - __builtin_clz(size));
        rep(i, parent2.size()) parent2[i].resize(size, -1);
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
            rep(i, size) parent2[pi + 1][i] = parent2[pi][parent2[pi][i]];
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
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int n, q;
    cin >> n;
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;
        l[x].push_back(y);
        l[y].push_back(x);
    }
    LCA lca(l, n, 1);
    cin >> q;
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        print(1 + lca.depth[a] + lca.depth[b] - 2 * lca.depth[lca.find(a, b)]);
    }


    return 0;
}

