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

template<typename T>
struct Compress {
    vector<T> v;

    constexpr Compress() : v() {}

    constexpr Compress(vector<T> v) : v(v) {
        build();
    }

    static constexpr Compress<T> with_sorted(vector<T> &&v) {
        return Compress<T>{v};
    }

    void build() {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }

    int compress(const T x) const {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    }

    const T &restore(const int i) const { return v[i]; }

    int operator()(const T &&x) const { return compress(x); }

    const T &operator[](const int i) const { return restore(i); }
};

int64 yoko[17][33000];
int64 tate[17][33000];
int64 dp[17][33000];

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int64 n;
    int64 x[16], y[16], p[16];
    cin >> n;
    rep(i, n) cin >> x[i] >> y[i] >> p[i];
    x[n] = y[n] = p[n] = 0;

    rep(i, n + 1) {
        rep(bit, 1 << n) {
            yoko[i][bit] = tate[i][bit] = 0;
            rep(k, n) if (bit & (1 << k)) {
                yoko[i][bit] += p[k] * abs(y[i] - y[k]);
                tate[i][bit] += p[k] * abs(x[i] - x[k]);
            }
        }
    }

    const int allbit = (1 << n) - 1;

    rep(bit, 1 << n) {
        dp[0][bit] = INF;
    }
    dp[0][0] = 0;
    rep(i, n) {
        rep(k, n) {
            rep(bit, 1 << n) {
                dp[i + 1][bit];
            }
        }
    }




    return 0;
}

/*
  ___   ___ _ __  _ __
 / _ \ / __| '_ \| '_ \
|  __/| (__| |_) | |_) |
 \___(_)___| .__/| .__/
           |_|   |_|
*/
