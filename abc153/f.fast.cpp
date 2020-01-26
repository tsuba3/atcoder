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

// begin fast io

char buf[10000000];
int bufi = 0;

template<typename T>
void readui(T &n) {
    n = 0;
    int c = buf[bufi++];
    for (; '0' <= c && c <= '9'; c = buf[bufi++])
        n = 10 * n + c - '0';
}

template<typename T>
void readi(T &n) {
    bool negative = false;
    if (buf[bufi] == '-') negative = true, bufi++;
    readui(n);
    if (negative) n = -n;
}

template<typename T>
void readuf(T &x) {
    x = 0;
    T y = 0;
    int z = 0;
    int c = buf[bufi++];
    for (; '0' <= c && c <= '9'; c = buf[bufi++])
        x = 10 * x + c - '0';
    if (buf[bufi - 1] == '.')
        for (; '0' <= c && c <= '9'; c = buf[bufi++], ++z)
            y = 10 * y + c - '0';
    x += y / pow(10, z);
}

template<typename T>
void readf(T &x) {
    bool negative = false;
    if (buf[bufi] == '-') negative = true, bufi++;
    readuf(x);
    if (negative) x = -x;
}

void reads(string &s) {
    const int begin = bufi;
    int c;
    while (c = buf[bufi++], c != ' ' && c != '\n') {}
    s = string(buf + begin, buf + bufi);
}

void readline(string &s) {
    const int begin = bufi;
    while (buf[bufi++] != '\n') {}
    s = string(buf + begin, buf + bufi);
}

// end fast io

int x[200200], h[200200], xx[200200], hh[200200];

void radix_sort(int n) {
    constexpr int b = 8;
    constexpr int mask = (1 << b) - 1;
    for (int k = 0; k < 4; ++k) {
        int bucket[1 << b] = {};
        int index[1 << b];
        for (int i = 0; i < n; ++i) bucket[mask & (x[i] >> (b*k))] += 1;
        index[0] = 0;
        for (int i = 0; i < (1 << b) - 1; ++i) index[i + 1] = index[i] + bucket[i];
        for (int i = 0; i < n; ++i) {
            int& j = index[mask & (x[i] >> (b*k))];
            xx[j] = x[i];
            hh[j] = h[i];
            ++j;
        }

        k += 1;

        memset(bucket, 0, sizeof bucket);
        for (int i = 0; i < n; ++i) bucket[mask & (xx[i] >> (b*k))] += 1;
        index[0] = 0;
        for (int i = 0; i < (1 << b) - 1; ++i) index[i + 1] = index[i] + bucket[i];
        for (int i = 0; i < n; ++i) {
            int& j = index[mask & (xx[i] >> (b*k))];
            x[j] = xx[i];
            h[j] = hh[i];
            ++j;
        }
    }
}
// begin monoid
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
// end monoid


/*
 * 遅延評価セグメントツリー
 * M はモノイド、Op は区間演算を表すモノイド、
 * f(m, op, n) は n 区間合成したモノイド m に演算子 op を作用した結果
 * f(m1*m2, op, n1+n2) == f(m1, op, n1) * f(m2, op, n2) が必要（分配法則）
 * op_cummutative: 演算子が可換かどうか、可換なら update が定数倍高速化する
 */
template<typename M, typename Op, typename M::type f(typename M::type const, typename Op::type const, int const), bool op_commutative>
class LazySegmentTree {
public:
    using MT = typename M::type;
    using OpT = typename Op::type;
    LazySegmentTree(const int n = 0) {
        depth = int (ceil(log2(max(2, n))));
        this->n = 1 << depth;
        v.resize(2 * this->n, M::unit);
        lazy.resize(2 * this->n, Op::unit);
    }
    template<typename I>
    void set(int l, int r, I it) {
        l += n; r += n;
        for (int i = l; i < r; ++i) v[i] = *it++;
    }
    /// 点取得 O(1)
    MT get(int i) {
        i += n;
        propagate(i);
        v[i] = f(v[i], lazy[i], 1);
        lazy[i] = Op::unit;
        return v[i];
    }
    /// 区間演算 O(log n)
    void update(int l, int r, OpT const op) {
        l += n; r += n;
        if (!op_commutative) propagate(l);
        if (!op_commutative) propagate(r - 1);
        for (int ll = l, rr = r; ll < rr; ll >>= 1, rr >>= 1) {
            if (ll & 1) lazy[ll] = Op::f(lazy[ll], op), ++ll;
            if (rr & 1) --rr, lazy[rr] = Op::f(lazy[rr], op);
        }
    }
// private:

    void propagate(int i) {
        for (int h = depth; h > 0; --h) {
            int x = i >> h;
            lazy[2 * x + 0] = Op::f(lazy[2 * x + 0], lazy[x]);
            lazy[2 * x + 1] = Op::f(lazy[2 * x + 1], lazy[x]);
            v[x] = f(v[x], lazy[x], 1 << h);
            lazy[x] = Op::unit;
        }
        v[i] = f(v[i], lazy[i], 1);
        v[i^1] = f(v[i^1], lazy[i^1], 1);
        lazy[i] = lazy[i^1] = Op::unit;
    }

    vector<MT> v;
    vector<OpT> lazy;
    int n;
    int depth;
};

// end segment_tree


int64 minint(int64 a, int64 b) { return min(a, b); }
int64 addint(int64 a, int64 b) { return a + b; }
int64 minusint(const int64 a, const int64 b, const int _) { return a - b; }

using M = Monoid<int64, minint>;
using Op = Monoid<int64, addint>;
template<> const int64 M::unit(INF64);
template<> const int64 Op::unit(0);
using Seg = LazySegmentTree<M, Op, minusint, true>;


int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int n, d, a;
    readui(n), readui(d), readui(a);
    rep(i, n) {
        int H;
        readui(x[i]), readui(H);
        h[i] = (H + a - 1) / a;
    }
    radix_sort(n);

    Seg seg(n);

    seg.set(0, n, h);

    int64 ans = 0;
    rep(i, n) {
        int64 c = seg.get(i);
        if (c <= 0) continue;
        ans += c;
        auto it = lower_bound(begin(x) + i, begin(x) + n, x[i] + 2 * d + 1);
        int j = (it - begin(x));
        seg.update(i, j, c);
    }

    print(ans);

    return 0;
}

