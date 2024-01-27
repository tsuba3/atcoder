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

bitset<7> dp[200200] = {};

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int8_t s[200200];
    bool taka[200200];
    int n;
    string ss, xx;
    cin >> n >> ss >> xx;
    rep(i, n) s[i] = (ss[i] - '0') % 7;
    rep(i, n) taka[i] = xx[i] == 'T';

    int b = 1;
    for (int i = n - 1; i >= 0; --i) {
        s[i] = (b * s[i]) % 7;
        b = (b * 10) % 7;
    }

    dp[n][0] = true;
    rep(i, n) {
        int t = n - i - 1;

        if (taka[t]) {
            dp[t] = dp[t + 1];
            rep(k, 7) dp[t][k] = dp[t][k] || dp[t + 1][(k + s[t]) % 7];
        } else {
            rep(k, 7) dp[t][k] = dp[t + 1][k] && dp[t + 1][(k + s[t]) % 7];
        }
    }

    if (dp[0][0]) {
        print("Takahashi");
    } else {
        print("Aoki");
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
