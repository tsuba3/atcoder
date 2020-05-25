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

template<typename T>
struct Compress {
    vector<T> v;
    constexpr Compress() : v() {}
    constexpr Compress(vector<T>&& v) : v(v) {
        build();
    }
    static constexpr Compress<T> with_sorted(vector<T>&& v) {
        return Compress<T>{v};
    }
    void build() {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    int compress(const T x) const {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    }
    const T& restore(const int i) const { return v[i]; }
    int operator()(const T&& x) const { return compress(x); }
    const T& operator[](const int i) const { return restore(i); }
};

bool kabe[6060][6060];
bool M[6060][6060];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int n, m;
    cin >> n >> m;
    Compress<int> X, Y;
    X.v.reserve(3030), Y.v.reserve(3030);
    X.v.push_back(0);
    X.v.push_back(-INF);
    X.v.push_back(INF);
    Y.v.push_back(0);
    Y.v.push_back(-INF);
    Y.v.push_back(INF);

    int a[1010], b[1010], c[1010], d[1010], e[1010], f[1010];
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i];
        X.v.push_back(a[i]);
        X.v.push_back(b[i]);
        Y.v.push_back(c[i]);
    }
    rep(i, m) {
        cin >> d[i] >> e[i] >> f[i];
        X.v.push_back(d[i]);
        Y.v.push_back(e[i]);
        Y.v.push_back(f[i]);
    }
    X.build();
    Y.build();

    rep(i, n) {
        int y = Y.compress(c[i]);
        for (int x = X.compress(a[i]), ed = X.compress(b[i]); x < ed; ++x) {
            kabe[2 * y][2 * x + 0] = true;
            kabe[2 * y][2 * x + 1] = true;
        }
    }
    rep(i, n) {
        int x = X.compress(d[i]);
        for (int y = Y.compress(e[i]), ed = Y.compress(f[i]); y < ed; ++y) {
            kabe[2 * y + 0][2 * x] = true;
            kabe[2 * y + 1][2 * x] = true;
        }
    }

    stack<pii> dfs;
    dfs.emplace(2 * X.compress(0) + 1, 2 * Y.compress(0) + 1);
    bool inf = false;
    while (!dfs.empty()) {
        int x = dfs.top().first;
        int y = dfs.top().second;
        dfs.pop();
        M[y][x] = true;
        rep(i, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (0 <= xx && xx < 2 * X.v.size() && 0 <= yy && yy < 2 * Y.v.size() && !kabe[yy][xx] && !M[yy][xx]) {
                dfs.emplace(xx, yy);
            }
        }
    }

    rep(x, 2 * X.v.size()) inf |= M[0][x];
    rep(x, 2 * X.v.size()) inf |= M[2 * Y.v.size() - 1][x];
    rep(y, 2 * Y.v.size()) inf |= M[y][0] || M[y][2 * X.v.size() - 1];
    if (inf) {
        print("INF");
        return 0;
    }

    int64 ans = 0;
    rep(y, Y.v.size() - 1) {
        rep(x, X.v.size() - 1) {
            if (M[2 * y + 1][2 * x + 1]) {
                ans += (int64) (Y.restore(y + 1) - Y.restore(y)) * (int64) (X.restore(x + 1) - X.restore(x));
            }
        }
    }

    print(ans);

    return 0;
}

