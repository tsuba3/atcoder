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

int depth[100100];
int parent[17][100100];

int parentn(int i, int n) {
    rep(j, 17) {
        if ((1 << j) & n) {
            i = parent[j][i];
        }
    }
    return i;
}

int find_lca(int a, int b) {
    if (a == b) return a;
    int da = depth[a], db = depth[b];
    if (da > db) a = parentn(a, da - db);
    else b = parentn(b, db - da);
    for (int p = (8 * sizeof(a) - __builtin_clz(min(da, db))); p >= 0; p--) {
        if (parent[p][a] != parent[p][b]) a = parent[p][a], b = parent[p][b];
    }
    return parent[0][a];
}

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int n, q;
    vector<int> v[100100];
    cin >> n;
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    memset(parent, -1, sizeof parent);
    memset(depth, -1, sizeof depth);
    stack<int> dfs;
    dfs.push(0);
    depth[0] = 0;
    while (!dfs.empty()) {
        int i = dfs.top();
        dfs.pop();
        for (int j : v[i]) if (depth[j] == -1) {
            depth[j] = depth[i] + 1;
            parent[0][j] = i;
            dfs.push(j);
        }
    }

    rep(i, 16) {
        rep(j, n) {
            parent[i + 1][j] = parent[i][parent[i][j]];
        }
    }

    cin >> q;
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int lca = find_lca(a, b);
        print(1 - 2 * depth[lca] + depth[a] + depth[b]);
    }

    return 0;
}

