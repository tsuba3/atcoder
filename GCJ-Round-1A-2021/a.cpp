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

template<typename S, typename T> bool chmin(S& a, const T& b) {
    if (a > b) return a = b, true; else return false;
}

template<typename S, typename T> bool chmax(S& a, const T& b) {
    if (a < b) return a = b, true; else return false;
}

// End of template.

int get_digits(int n) {
    if (n <= 9) return 1;
    int ans = 0;
    while (n >= 1) {
        ans += 1;
        n /= 10;
    }
    return ans;
}

int64 p10(int n) {
    int64 res = 1;
    rep(i, n) res *= 10;
    return res;
}

void solve(int ti) {
    int n;
    int64 x[110];
    int64 y[110];
    int ans = 0;
    cin >> n;
    rep(i, n) cin >> x[i];

    y[0] = x[0];
    for (int i = 1; i < n; ++i) {
        int a = y[i - 1], b = x[i];
        int da = get_digits(a), db = get_digits(b);
        if (da < db) {
            y[i] = b;
        } else if (da == db) {
            if (a < b) {
                y[i] = b;
            } else {
                y[i] = b * 10;
                ans += 1;
            }
        } else {
            if (a / p10(da - db) < b) {
                y[i] = b * p10(da - db);
                ans += da - db;
            } else if (a % p10(da - db) == p10(da - db) - 1) {
                y[i] = b * p10(da - db + 1);
                ans += da - db + 1;
            } else {
                y[i] = b * p10(da - db) + (a % p10(da - db));
                ans += da - db + 1;
            }
        }
    }

    cout << "Case #" << ti << ": " << ans << '\n';
}

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int t;
    cin >> t;
    rep(ti, t) solve(ti + 1);

    return 0;
}

/*
  __ _   ___ _ __  _ __
 / _` | / __| '_ \| '_ \
| (_| || (__| |_) | |_) |
 \__,_(_)___| .__/| .__/
            |_|   |_|
*/