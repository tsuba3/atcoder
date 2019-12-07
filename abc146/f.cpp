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

template<typename T, T f_(T const, T const)>
class Monoid {
public:
    using type = T;

    static T f(T const a, T const b) {
        return f_(a, b);
    }

    static const T unit;

    template<typename I>
    static T concat(I const& begin, I const& end) {
        return accumulate(begin, end, unit, f);
    }

    static T pow(T base, int exp) {
        T res = unit;
        while (exp > 0) {
            if (exp & 1) res = f(base, res);
            base = f(base, base);
            exp >>= 1;
        }
        return res;
    }
};

template<typename M, typename Op = M, typename M::type f(typename M::type const, typename Op::type const) = M::f>
class LazySegmentTree {
public:
    using MT = typename M::type;
    using OpT = typename Op::type;
    LazySegmentTree(const int n) {
        depth = int (ceil(log2(n)));
        this->n = 1 << depth;
        v.resize(2 * this->n, M::unit);
        lazy.resize(2 * this->n, Op::unit);
    }
    void set(int i, MT const m) {
        i += n;
        v[i] = m;
        re_calc(i, i + 1);
    }
    void set(int l, int r, MT const m) {
        l += n; r += n;
        for (int i = l; i < r; ++i) v[i] = m;
        re_calc(l, r);
    }
    template<typename I>
    void set(int l, int r, I it) {
        l += n; r += n;
        for (int i = l; i < r; ++i) v[i] = *it++;
        re_calc(l, r);
    }
    MT get(int const i) {
        return v[n + i];
    }
    MT get(int l, int r) {
        l += n; r += n;
        int d = 0;
        MT res = M::unit;
        while (l < (r >> d)) {
            if (l & 1) { // l is right side of parent or root
                res = M::f(res, v[l]);
                l += 1;
            }
            l /= 2;
            d++;
        }
        while (d >= 0) {
            l = 2 * l;
            d--;
            if (l < (r >> d)) {
                res = M::f(res, v[l]);
                l += 1;
            }
        }
        return res;
    }
    /// 全区間取得 O(1)
    MT get() const {
        if (lazy[1] != Op::unit) {
            lazy[2] = Op::f(lazy[2], lazy[1]);
            lazy[3] = Op::f(lazy[3], lazy[1]);
            v[1] = f(v[1], Op::pow(lazy[1], depth + 1));
            lazy[1] = Op::unit;
        }
        return v[1];
    }
    /// 点演算 O(1)
    void update(int const i, OpT const op) {
        lazy[n + i] = Op::f(lazy[n + i], op);
    }
    /// 区間演算 O(log(r - l))
    void update(int l, int r, OpT const op) {
        l += n; r += n;
        int d = 0;
        while (l < (r >> d)) {
            if (l & 1) { // l is right side of parent or root
                lazy[l] = Op::f(lazy[l], op);
                l += 1;
            }
            l /= 2;
            d++;
        }
        while (d >= 0) {
            l = 2 * l;
            d--;
            if (l < (r >> d)) {
                lazy[l] = Op::f(lazy[l], op);
                l += 1;
            }
        }
    }
    /// 全区間演算 O(1)
    void update(OpT const op) {
        lazy[1] = Op::f(lazy[1], op);
    }
// private:

    void re_calc(int l, int r) {
        r--;
        l >>= 1; r >>= 1;
        while (l > 0) {
            for (int i = l; i <= r; ++i) v[i] = M::f(v[2 * i], v[2 * i + 1]);
            l >>= 1; r >>= 1;
        }
    }

    vector<MT> v;
    vector<OpT> lazy;
    int n;
    int depth;
};

// End of template.

int minint(int a, int b) { return min(a, b); }

template<>
int Monoid<int, minint>::pow(int base, int exp) {
    return base;
}

template<>
const int Monoid<int, minint>::unit(INF);

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> s;
    n = s.length();

    using M = Monoid<int, minint>;
    using ST = LazySegmentTree<M>;

    ST st(n + 1);
    st.set(n, 0);


    return 0;
}


