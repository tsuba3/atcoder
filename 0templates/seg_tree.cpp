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

template<typename T> T identity(const T x) { return x; }

template<typename M, typename Op = M, typename M::type f(typename M::type const, typename Op::type const) = M::f>
class SegmentTree {
public:
    using MT = typename M::type;
    using OpT = typename Op::type;
    SegmentTree(const int n) {
        depth = int (ceil(log2(n)));
        this->n = 1 << depth;
        v.resize(2 * this->n, M::unit);
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
    MT get() const {
        return v[1];
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
    PT op(int const i, PT const p);
    PT op(int const1 i, int , PT const p);
// private:

    void re_calc(int l, int r) {
        r--;
        l >>= 1; r >>= 1;
        while (l > 0) {
            for (int i = l; i <= r; ++i) v[i] = M::f(v[2 * i], v[2 * i + 1]);
            l >>= 1; r >>= 1;
        }
    }
    
    vector<OpT> lazy;
    vector<MT> v;
    int n;
    int depth;
};


// End of template.

template<typename T>
T add(T const a, T const b) {
    return a + b;
}

template<>
int Monoid<int, add<int>>::pow(int base, int exp) {
    return base * exp;
}

template<>
const int Monoid<int, add<int>>::unit(0);

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    using M = Monoid<int, add<int>>;
    using ST = SegmentTree<M>;

    ST st(6);

    debug(st.depth);
    debug(st.v.size());
    st.set(3, 4);
    debug(st.get(0));
    dbg(st.v);

    int v[] = {1, 2, 3, 4};
    st.set(0, 5, 1);
    dbg(st.v);
    st.set(0, 4, begin(v));
    dbg(st.v);

    debug(st.get(3));
    debug(st.get(0, 8));
    debug(st.get());

    return 0;
}

