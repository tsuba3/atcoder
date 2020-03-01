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


// End of template.

int n, m, k, a[100100], b[100100], c[100100], d[100100];
UnionFind uf(100100);
int cnt[100100];
int ans[100100];
unordered_set<int> minu[100100];

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    cin >> n >> m >> k;
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        uf.unite(a[i], b[i]);
    }
    rep(i, k) {
        cin >> c[i] >> d[i];
        c[i]--, d[i]--;
    }
    rep(i, n) uf.root(i);
    rep(i, n) cnt[uf.v[i]] += 1;

    rep(i, n) ans[i] = cnt[uf.root(i)] - 1;

    rep(i, m) if (uf.is_same(a[i], b[i])) minu[a[i]].insert(b[i]), minu[b[i]].insert(a[i]);
    rep(i, k) if (uf.is_same(c[i], d[i])) minu[c[i]].insert(d[i]), minu[d[i]].insert(c[i]);

    rep(i, n - 1) cout << (ans[i] - (minu[i].size())) << ' ';
    cout << (ans[n - 1] - (minu[n - 1].size())) << '\n';


    return 0;
}

