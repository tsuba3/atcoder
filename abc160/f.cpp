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

// Begin Mod
template<typename T, T mod_, bool is_prime = true>
class Mod {
public:
    using Self = Mod<T, mod_, is_prime>;
    T value;
    static constexpr T mod = mod_;
    constexpr Mod() : value(0) {}
    constexpr Mod(T x) : value(x % mod) {}
    explicit operator T&() { return value; }
    Self operator +(Self const x) const { return (value + x.value) % mod; }
    constexpr Self operator *(Self const x)  { return (value * x.value) % mod; }
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
    constexpr Self inv_ce() const {
        T a = value, b = mod, u = 1, v = 0, t = 0;
        while (b) {
            T t = a / b;
            a -= t * b; t = a; b = a; a = t;
            u -= t * v; t = u; u = v; v = t;
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

template<typename T, T mod>
istream& operator>>(istream& stream, Mod<T, mod>& m) {
    return stream >> m.value;
}

template<typename T, T mod>
ostream& operator<<(ostream& stream, const Mod<T, mod>& m) {
    return stream << m.value;
}
// End Mod
constexpr int64 mod = 1e9 + 7;
using M = Mod<int64, mod>;

constexpr struct Fact {
    M fact[200200];
    constexpr Fact() : fact() {
        fact[0] = 1;
        rep(i, 200199) fact[i + 1] = fact[i] * (i + 1);
    }
    constexpr M operator()(int i) const { return fact[i]; }
} fact;
/*
constexpr struct FactInv {
    M inv[200200];
    constexpr FactInv() : inv() {
        rep(i, 200200) inv[i] = fact(i).inv_ce();
    }
    M operator()(int i) const { return inv[i]; }
} inv;
*/
struct A { int sz; M x; };
ostream& operator<<(ostream& stream, const A& a) {
    return stream << '{' << a.sz << ", " << a.x << '}';
}

vector<pair<int, A>> v[200200];
int ans[200200];

A dfs1(int i, int parent) {
    int sz = 1;
    M m = 1;
    for (auto& j : v[i]) if (j.first != parent) {
        j.second = dfs1(j.first, i);
        sz += j.second.sz;
        m *= j.second.x;
        m /= fact(j.second.sz);
    }
    m *= fact(sz - 1);
    return A{sz, m};
}

void dfs2(int i, int parent, A a) {
    A total{1, 1};
    total.sz += a.sz;
    total.x *= a.x;
    total.x /= fact(a.sz);
    for (const auto& j : v[i]) if (j.first != parent) {
        total.sz += j.second.sz;
        total.x *= j.second.x;
        total.x /= fact(j.second.sz);
    }
    total.x *= fact(total.sz - 1);
    ans[i] = total.x.value;
    debug3(i, a, ans[i]);
    debug2(total.x, total.sz);
    for (const auto& j : v[i]) if (j.first != parent) {
        dfs2(j.first, i, A{total.sz - j.second.sz, total.x / j.second.x * fact(j.second.sz)});
    }
}

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int n;
    cin >> n;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(make_pair(b, A{0,0}));
        v[b].push_back(make_pair(a, A{0,0}));
    }

    dfs1(0, -1).x.value;
    dfs2(0, -1, A{0, 1});
    rep(i, n) print(ans[i]);

    return 0;
}

