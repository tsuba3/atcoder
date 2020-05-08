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
char buf[10000000], OUT[10000000];
int bufi = 0, outi = 0;

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

const char digit_pairs[] = {
  "00010203040506070809"
  "10111213141516171819"
  "20212223242526272829"
  "30313233343536373839"
  "40414243444546474849"
  "50515253545556575859"
  "60616263646566676869"
  "70717273747576777879"
  "80818283848586878889"
  "90919293949596979899"
};

void writec(char c) {
    OUT[outi++] = c;
}

void writes(const string s) {
    memcpy(OUT + outi, s.c_str(), s.size());
    outi += s.size();
}

template<typename T>
void writeui(T n) {
    if (n == 0) OUT[outi++] = '0';
    int size;
    if (n >= 1e12) {
        if (n >= 1e16) {
            if (n >= 1e18) {
                if (n >= 1e19) size = 20;
                else size = 19;
            } else {
                if (n >= 1e17) size = 18;
                else size = 17;
            }
        } else {
            if (n >= 1e14) {
                if (n >= 1e15) size = 16;
                else size = 15;
            } else {
                if (n >= 1e13) size = 14;
                else size = 13;
            }
        }
    } else if (n >= 1e4) {
        if (n >= 1e8) {
            if (n >= 1e10) {
                if (n >= 1e11) size = 12;
                else size = 11;
            } else {
                if (n >= 1e9) size = 10;
                else size = 9;
            }
        } else {
            if (n >= 1e6) {
                if (n >= 1e7) size = 8;
                else size = 7;
            } else {
                if (n >= 1e5) size = 6;
                else size = 5;
            }
        }
    } else {
        if (n >= 1e2) {
            if (n >= 1e3) size = 4;
            else size = 3;
        } else {
            if (n >= 1e1) size = 2;
            else size = 1;
        }
    }
    char *c = OUT + outi + size;
    outi += size;
    while (n >= 100) {
        int x = n % 100;
        n /= 100;
        *--c = digit_pairs[2 * x + 1];
        *--c = digit_pairs[2 * x];
    }
    while (n > 0) {
        *--c = '0' + (n % 10);
        n /= 10;
    }
}

template<typename T>
void writei(T n) {
    if (n < 0) {
        writec('-');
        writeui(-n);
    } else {
        writeui(n);
    }
}

// end fast io


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

// begin segment_tree
// monoid に依存
template<typename M>
typename M::type st_default(typename M::type const m, typename M::type const op, int const b) {
    return M::f(m, op);
}

/*
 * セグメントツリー
 */
template<typename M>
class SegmentTree {
public:
    using MT = typename M::type;
    SegmentTree(const int n) {
        depth = int (ceil(log2(max(2, n))));
        this->n = 1 << depth;
        v.resize(2 * this->n, M::unit);
    }
    void set(int i, MT const m) {
        i += n;
        v[i] = m;
        build(i, i + 1);
    }
    void set(int l, int r, MT const m) {
        l += n; r += n;
        for (int i = l; i < r; ++i) v[i] = m;
        build(l, r);
    }
    template<typename I>
    void set(int l, int r, I it) {
        l += n; r += n;
        for (int i = l; i < r; ++i) v[i] = *it++;
        build(l, r);
    }
    MT get() const {
        return v[1];
    }
    MT get(int const i) {
        return v[n + i];
    }
    MT get(int l, int r) {
        MT L = M::unit, R = M::unit;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = M::f(L, v[l++]);
            if (r & 1) R = M::f(v[--r], R);
        }
        return M::f(L, R);
    }

    void build(int l, int r) {
        r--;
        l >>= 1; r >>= 1;
        while (l > 0) {
            for (int i = l; i <= r; ++i) v[i] = M::f(v[2 * i], v[2 * i + 1]);
            l >>= 1; r >>= 1;
        }
    }

    vector<MT> v;
    int n;
    int depth;
};



/*
 * 遅延評価セグメントツリー
 * M はモノイド、Op は区間演算を表すモノイド、
 * f(m, op, n) は n 区間合成したモノイド m に演算子 op を作用した結果
 * f(m1*m2, op, n1+n2) == f(m1, op, n1) * f(m2, op, n2) が必要（準同型）
 * op_cummutative: 演算子が可換かどうか、可換なら update が定数倍高速化する
 */
template<typename M, typename Op = M, typename M::type f(typename M::type const, typename Op::type const, int const) = st_default<M>, bool op_commutative = false>
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
    void set(MT const m) {
        fill(begin(v) + n, begin(v) + 2 * n, m);
        fill(begin(lazy), end(lazy), Op::unit);
        build(n, 2*n);
    }
    void set(int i, MT const m) {
        i += n;
        propagate(i);
        v[i] = m;
        lazy[i] = Op::unit;
        build(i, i + 1);
        recalc(i);
    }
    void set(int l, int r, MT const m) {
        l += n; r += n;
        propagate(l);
        propagate(r - 1);
        for (int i = l; i < r; ++i) v[i] = m;
        for (int ll = l, rr = r; ll < rr; ll >>= 1, rr >>= 1) {
            for (int i = ll; i < rr; ++i) lazy[i] = Op::unit;
        }
        build(l, r);
        recalc(l);
        recalc(r - 1);
    }
    template<typename I>
    void set(int l, int r, I it) {
        l += n; r += n;
        propagate(l);
        propagate(r - 1);
        for (int i = l; i < r; ++i) v[i] = *it++;
        for (int ll = l, rr = r; ll < rr; ll >>= 1, rr >>= 1) {
            for (int i = ll; i < rr; ++i) lazy[i] = Op::unit;
        }
        build(l, r);
        recalc(l);
        recalc(r - 1);
    }
    /// 点取得 O(log n)
    MT get(int i) {
        i += n;
        propagate(i);
        v[i] = f(v[i], lazy[i], 1);
        lazy[i] = Op::unit;
        return v[i];
    }
    /// 区間取得 O(log n)
    MT get(int l, int r) {
        l += n; r += n;
        propagate(l);
        propagate(r - 1);
        MT L = M::unit, R = M::unit;
        for (int d = 0; l < r; l >>= 1, r >>= 1, ++d) {
            if (l & 1) {      L = M::f(L, f(v[l], lazy[l], 1 << d)); ++l; }
            if (r & 1) { --r; R = M::f(f(v[r], lazy[r], 1 << d), R);      }
        }
        return M::f(L, R);
    }
    /// 点演算 O(log n)
    void update(int i, OpT const op) {
        i += n;
        if (!op_commutative) propagate(i);
        lazy[i] = Op::f(lazy[i], op);
        recalc(i);
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
        recalc(l);
        recalc(r - 1);
    }
    /// 全て評価 O(n)
    void eval() {
        for (int i = 1; i < n; ++i) {
            lazy[2 * i + 0] = Op::f(lazy[2 * i + 0], lazy[i]);
            lazy[2 * i + 1] = Op::f(lazy[2 * i + 1], lazy[i]);
        }
        for (int i = n; i < 2 * n; ++i) {
            v[i] = f(v[i], lazy[i], 1);
        }
        fill(lazy.begin(), lazy.end(), Op::unit);
        build(n, 2*n);
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

    void recalc(int i) {
        int d = 0;
        while (i >>= 1) {
            MT left = f(v[2 * i], lazy[2 * i], 1 << d);
            MT right = f(v[2 * i + 1], lazy[2 * i + 1], 1 << d);
            v[i] = M::f(left, right);
            ++d;
        }
    }

    void build(int l, int r) {
        --r;
        while (l < r) {
            ++l; --r;
            l >>= 1; r >>= 1;
            for (int i = l; i <= r; ++i) v[i] = M::f(v[2 * i], v[2 * i + 1]);
        }
    }

    vector<MT> v;
    vector<OpT> lazy;
    int n;
    int depth;
};

// end segment_tree

int64 identity(int64 lhs, int64 rhs) { return lhs; }
int64 iadd(int64 lhs, int64 rhs) { return lhs + rhs; }
int64 imax(int64 lhs, int64 rhs) { return max(lhs, rhs); }
pll pll_min_add(pll lhs, pll rhs) {
    return make_pair(min(lhs.first, rhs.first - lhs.second), lhs.second + rhs.second);
}

using Mid = Monoid<int64, identity>;
using Madd = Monoid<int64, iadd>;
using Mmax = Monoid<int64, imax>;
using Mpll = Monoid<pll, pll_min_add>;

template<> const int64 Mid::unit(1e18);
template<> const int64 Madd::unit(0);
template<> const int64 Mmax::unit(-1e18);
template<> const pll Mpll::unit(make_pair(1e18, 0));

int64 f(int64 m, int64 op, int length) { return m + op; }
int64 g(int64 m, pll op, int length) {
    return min(m, op.first) + op.second;
}

using Seg1 = LazySegmentTree<Mid, Mpll, g, false>;
using Seg2 = LazySegmentTree<Mmax, Madd, f, true>;

struct Q {
    int l;
    int r;
    int x;
    int y;
};

Q q[200200];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int n, qn;
    readui(n), readui(qn);
    rep(i, qn) {
        readui(q[i].l);
        readui(q[i].r);
        readi(q[i].x);
        readi(q[i].y);
        q[i].l--;
    }

    Seg1 seg1(n);
    for (int i = qn - 1; i >= 0; --i) {
        seg1.update(q[i].l, q[i].r, make_pair(q[i].y, -q[i].x));
    }
    seg1.eval();

    Seg2 seg2(n);
    seg2.set(0, n, seg1.v.begin() + seg1.n);
    bool ok = true;
    rep(i, qn) {
        seg2.update(q[i].l, q[i].r, q[i].x);
        ok &= seg2.get(q[i].l, q[i].r) == q[i].y;
    }

    if (ok) {
        writes("OK\n");
        rep(i, n - 1) writei(min(max(seg1.v[seg1.n + i], (int64) -1e18), (int64)1e18)), writec(' ');
        writei(min(max(seg1.v[seg1.n + n - 1], (int64) -1e18), (int64)1e18));
        writec('\n');
    } else {
        writes("NG\n");
    }

    cout.write(OUT, outi);
    return 0;
}

