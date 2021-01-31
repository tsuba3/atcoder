/*                         _
                        _ooOoo_
                       o8888888o
                       88" . "88
                       (| -_- |)
                       O\  =  /O
                    ____/`---'\____
                  .'  \\|     |//  `.
                 /  \\|||  :  |||//  \
                /  _||||| -:- |||||_  \
                |   | \\\  -  /'| |   |
                | \_|  `\`---'//  |_/ |
                \  .-\__ `-. -'__/-.  /
              ___`. .'  /--.--\  `. .'___
           ."" '<  `.___\_<|>_/___.' _> \"".
          | | :  `- \`. ;`. _/; .'/ /  .' ; |
          \  \ `-.   \_\_`. _.'_/_/  -' _.' /
===========`-.`___`-.__\ \___  /__.-'_.'_.-'================

                  Please give me AC.
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <complex>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <chrono>
#include <random>

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
#ifdef ONLINE_JUDGE
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define dbg(v)
#else
#define debug(x) cerr << #x << ": " << (x) << '\n'
#define debug2(x, y) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'
#define dbg(v) for (size_t _ = 0; _ < v.size(); ++_){cerr << #v << "[" << _ << "] : " << v[_] << '\n';}
#endif

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

template<typename T> T lcm(const T a, const T b) {
    return a / gcd(a, b) * b;
}

template<typename T> bool chmin(T& a, const T& b) {
    if (a > b) return a = b, true; else return false;
}

template<typename T> bool chmax(T& a, const T& b) {
    if (a < b) return a = b, true; else return false;
}

// End of template.
// Begin UnionFind
class UnionFind {
public:
    explicit UnionFind(int const size) {
        v.resize(size);
        rep(i, size) v[i] = i;
    }
    vector<int> v;
    bool is_same(int const i, int const j) {
        return root(i) == root(j);
    }
    void unite(int const i, int const j) {
        const int ri = root(i);
        const int rj = root(j);
        if (ri == rj) return;
        v[rj] = ri;
    }
    int root(int const i) {
        if (v[i] == i) return i;
        return v[i] = root(v[i]);
    }
};
// End UnionFind


int s[140000][17];

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int n, m, k, c[20], d[20][20];
    cin >> n >> m;
    vector<vector<int>> vec(n);
    UnionFind uf(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        vec[a].push_back(b);
        vec[b].push_back(a);
        uf.unite(a, b);
    }
    cin >> k;
    rep(i, k) {
        cin >> c[i];
        c[i]--;
    }

    bool ok = true;
    rep(ci, k) ok &= uf.is_same(c[0], c[ci]);
    if (!ok) {
        print(-1);
        return 0;
    }

    rep(ci, k) {
        queue<int> bfs;
        vector<int> dp(n, INF);
        dp[c[ci]] = 0;
        bfs.push(c[ci]);
        while (!bfs.empty()) {
            int u = bfs.front();
            bfs.pop();
            for (int v : vec[u]) if (dp[v] == INF) {
                dp[v] = dp[u] + 1;
                bfs.push(v);
            }
        }
        rep(cj, k) d[ci][cj] = dp[c[cj]];
    }

    rep(i, k) {
        rep(j, k) cerr << d[i][j] << ' ';
        cerr << '\n';
    }

    rep(bit, 1 << k) rep(ci, k) s[bit][ci] = INF;
    rep(ci, k) s[0][ci] = 1;
    rep(bit, 1 << k) rep(u, k) rep(v, k) {
        chmin(s[bit | (1 << v)][v], s[bit][u] + d[u][v]);
    }

    int ans = INF;
    rep(ci, k) chmin(ans, s[(1 << k) - 1][ci]);
    print(ans);


    return 0;
}

/*
  ___   ___ _ __  _ __
 / _ \ / __| '_ \| '_ \
|  __/| (__| |_) | |_) |
 \___(_)___| .__/| .__/
           |_|   |_|
*/
