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

// End of template.


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
 * f(m1*m2, op, n1+n2) == f(m1, op, n1) * f(m2, op, n2) が必要（分配法則）
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
        build(i);
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
        build(l);
        build(r - 1);
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
        build(l);
        build(r - 1);
    }
    /// 点取得 O(1)
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
        //propagate(l);
        //propagate(r - 1);
        MT L = M::unit, R = M::unit;
        for (int d = 0; l < r; l >>= 1, r >>= 1, ++d) {
            if (l & 1) {      L = M::f(L, f(v[l], lazy[l], 1 << d)); ++l; }
            if (r & 1) { --r; R = M::f(f(v[r], lazy[r], 1 << d), R);      }
        }
        return M::f(L, R);
    }
    /// 全区間取得 O(1)
    MT get() const {
        return f(v[1], lazy[1], 1 << depth);
    }
    /// 点演算 O(log n)
    void update(int i, OpT const op) {
        i += n;
        if (!op_commutative) propagate(i);
        lazy[i] = Op::f(lazy[i], op);
        build(i);
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
        //build(l);
        //build(r - 1);
    }
    /// 全区間演算 O(1)
    void update(OpT const op) {
        lazy[1] = Op::f(lazy[1], op);
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

    void build(int i) {
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

int add(int a, int b) { return a + b; }
int intmin(int a, int b) { return min(a, b); }

template<> const int Monoid<int, add>::unit(0);
template<> const int Monoid<int, intmin>::unit(INF);

int add_add(int m, int op, int n) { return m + op; }

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int s[100100], t[100100];
    cin >> n >> m;
    rep(i, m) { cin >> s[i] >> t[i]; s[i]--; }

    LazySegmentTree<Monoid<int, intmin>, Monoid<int, add>, add_add, true> seg(n);
    seg.set(0, n, 0);

    vector<int> ans;
    rep(i, m) seg.update(s[i], t[i], 1);
    seg.eval();
    rep(i, m) {
        if (seg.get(s[i], t[i]) >= 2) ans.push_back(i + 1);
    }

    print(ans.size());
    for (const int& x : ans) print(x);

    return 0;
}

