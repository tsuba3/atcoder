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

pll dp[200200][2];

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int n;
    int64 left[200200], right[200200];
    bool e[200200];
    cin >> n;
    rep(i, n) {
        left[i] = INF64;
        right[i] = -INF64;
        e[i] = false;
    }
    rep(i, n) {
        int x, c;
        cin >> x >> c;
        c--;
        chmin(left[c], x);
        chmax(right[c], x);
        e[c] = true;
    }
    e[n] = true;
    left[n] = right[n] = 0;

    for (auto d : dp) rep(i, 2) d[i] = {INF64, 0};
    dp[0][0] = dp[0][1] = {0, 0};
    rep(c, n + 1) {
        rep(k, 2) {
            const auto [t, x] = dp[c][k];
            debug2(t, x);
            if (!e[c]) {
                dp[c + 1][k] = dp[c][k];
            } else {
                if (chmin(dp[c + 1][0].first, t + abs(right[c] - x) + abs(left[c] - right[c])))
                    dp[c + 1][0].second = left[c];

                if (chmin(dp[c + 1][1].first, t + abs(left[c] - x) + abs(left[c] - right[c])))
                        dp[c + 1][1].second = right[c];
            }
        }
    }

    print(min(dp[n + 1][0].first, dp[n + 1][1].first));

    return 0;
}

/*
  ___   ___ _ __  _ __
 / _ \ / __| '_ \| '_ \
|  __/| (__| |_) | |_) |
 \___(_)___| .__/| .__/
           |_|   |_|
*/
