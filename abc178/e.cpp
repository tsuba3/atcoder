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
#ifdef ONLINE_JUDGE
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define dbg(v)
#else
#define debug(x) cerr << #x << ": " << (x) << '\n'
#define debug2(x, y) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'
#define dbg(v) for (size_t _ = 0; _ < v.size(); ++_){cerr << #v << "[" << _ << "] : " << v[_] << '\n';}
#endif

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
// begin swag
// monoid に依存

/*
 * SWAG (Sliding-Window Aggregation Algorithms)
 * 合計を定数時間で計算できるキュー
 */
template<typename M>
class SWAG {
public:
    using MT = typename M::type;
    SWAG(): right_sum(M::unit) {}

    // O(1)
    MT get() const {
        if (left.empty())
            return right_sum;
        else
            return M::f(left[left.size() - 1].second, right_sum);
    }

    // 末尾に追加 O(1)
    void push_back(MT const m) {
        right_sum = M::f(right_sum, m);
        right.push_back(m);
    }

    // 先頭を削除 ならしO(1)
    void pop_front() {
        if (left.empty()) swap();
        left.pop_back();
    }

    int size() const {
        return left.size() + right.size();
    }

    void reserve(int const n) {
        right.reserve(n);
    }

    MT operator[](int const i) const {
        if (i >= left.size())
            return right[i - left.size()];
        else
            return left[left.size() - i - 1].first;
    }

private:
    void swap() {
        // assert(left.empty());
        const int n = right.size();
        MT sum = M::unit;
        left.reserve(n);
        right_sum = M::unit;
        rep(i, n) {
            sum = M::f(right[n - i - 1], sum);
            left.emplace_back(make_pair(right[n - i - 1], sum));
        }
        right.clear();
    }

    vector<pair<MT, MT>> left;
    vector<MT> right;
    MT right_sum;
};

// end swag


int64 max_int64(int64 a, int64 b) { return max(a, b); }
using M = Monoid<int64, max_int64>;
template<> const int64 M::unit(-INF64);

struct P {
        int64 x;
        int64 y;
    };

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int n;
    P p[200200];
    cin >> n;
    rep(i, n) cin >> p[i].x >> p[i].y;
    sort(begin(p), begin(p) + n, [](P lhs, P rhs) {
        return lhs.x < rhs.x;
    });

    SWAG<M> ps, ms;
    rep(i, n) {
        ps.push_back(p[i].x + p[i].y);
        ms.push_back(p[i].x - p[i].y);
    }

    int64 ans = 0;
    rep(i, n - 1) {
        int64 x0 = p[i].x, y0 = p[i].y;
        ps.pop_front();
        ms.pop_front();
        chmax(ans, ps.get() - y0 - x0);
        chmax(ans, ms.get() + y0 - x0);
    }

    print(ans);

    return 0;
}

/*
  ___   ___ _ __  _ __
 / _ \ / __| '_ \| '_ \
|  __/| (__| |_) | |_) |
 \___(_)___| .__/| .__/
           |_|   |_|
*/
