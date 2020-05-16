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
const int INF = (1 << 30) - 1;
const int64 INF64 = (1LL << 62) - 1;

template<typename T>
T gcd(T a, T b) {
    if (a < b) return gcd(b, a);
    T r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

template<typename T>
T lcm(const T a, const T b) {
    return a / gcd(a, b) * b;
}

template<typename T>
bool chmin(T &a, const T &b) {
    if (a > b) return a = b, true; else return false;
}

template<typename T>
bool chmax(T &a, const T &b) {
    if (a < b) return a = b, true; else return false;
}

// End of template.

struct V {
    int i;
    int ginka;
};

constexpr int fare_max = 2500;

template <typename T> struct A {
    T a[52][fare_max];
    T& operator[](V v) {
        return a[v.i][v.ginka];
    }
};

struct Edge {
    V to;
    int64 time;
};

A<int64> dp;
A<bool> done;
A<vector<Edge>> vec;

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int n, m, s0;
    cin >> n >> m >> s0;
    rep(i, m) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--, v--;
        for (int ginka = a; ginka <= fare_max; ++ginka) vec[{u, ginka}].emplace_back(Edge{{v, ginka - a}, b});
        for (int ginka = a; ginka <= fare_max; ++ginka) vec[{v, ginka}].emplace_back(Edge{{u, ginka - a}, b});
    }

    rep(i, n) {
        int c, d;
        cin >> c >> d;
        for (int ginka = 0; ginka < fare_max; ++ginka) vec[{i, ginka}].emplace_back(Edge{{i, min(ginka + c, fare_max)}, d});
    }

    for (int i = 0; i < n; ++i) for (int fare = 0; fare <= fare_max; ++fare) dp[{i, fare}] = INF64;
    auto comp = [](V lhs, V rhs) {
        return dp[lhs] < dp[rhs];
    };
    priority_queue<V, vector<V>, decltype(comp)> queue(comp);
    dp[{0, min(fare_max, s0)}] = 0;
    queue.emplace(V{0, min(fare_max, s0)});

    while (!queue.empty()) {
        V v = queue.top();
        queue.pop();
        if (done[v]) continue;
        done[v] = true;
        for (auto e : vec[v]) {
            if (chmin(dp[e.to], dp[v] + e.time)) {
                queue.emplace(e.to);
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        int64 t = INF64;
        for (int fare = 0; fare <= fare_max; ++fare) chmin(t, dp[{i, fare}]);
        print(t);
    }

    return 0;
}

