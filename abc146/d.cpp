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

// Begin Mod
template<typename T, T mod_, bool is_prime = true>
class Mod {
public:
    using Self = Mod<T, mod_, is_prime>;
    T value;
    static constexpr T mod = mod_;
    Mod(T x) { value = x % mod; }
    explicit operator T&() { return value; }
    Self operator +(Self const x) const { return (value + x.value) % mod; }
    Self operator *(Self const x) const { return (value * x.value) % mod; }
    Self operator -(Self const x) const { return (mod + value - x.value) % mod; }
    Self operator /(Self const x) const { return (value * x.inv().value) % mod; }
    Self operator +=(Self const x) { return value = (value + x.value) % mod; }
    Self operator *=(Self const x) { return value = (value * x.value) % mod; }
    Self operator -=(Self const x) { return value = (mod + value - x.value) % mod; }
    Self operator /=(Self const x) { return value = (value * x.inv().value) % mod; }
    Self inv() const {
        T a = value, b = mod, u = 1, v = 0;
        while (b) {
            T t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= mod;
        if (u < 0) u += mod;
        return u;
    }
    Self pow(int e) const {
        if (e < 0) return inv().pow(-e);
        if (is_prime) e %= mod - 1;
        Self base = value;
        Self res = 1;
        while (e > 0) {
            if (e & 1) res *= base;
            base *= base;
            e >>= 1;
        }
        return res;
    }
};
// End Mod

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

int n;
int a[100100], b[100100];
vector<pii> adj[100100];
int ans[100100];

void dfs(int u, int v, int e) {
    int i = 1;
    for (auto p : adj[v]) {
        int w = p.first;
        int idx = p.second;
        if (ans[idx] != -1) continue;
        ans[idx] = i++;
        if (ans[idx] == e) ans[idx] = i++;
        dfs(v, w, ans[idx]);
    }
};


int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    rep(i, n - 1) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        adj[a[i]].push_back(make_pair(b[i], i));
        adj[b[i]].push_back(make_pair(a[i], i));
    }

    memset(ans, -1, sizeof ans);

    dfs(-1, 0, -1);
    int k = 0;
    rep(i, n - 1) k = max(k, ans[i]);

    print(k);
    rep(i, n - 1) print(ans[i]);

    return 0;
}

