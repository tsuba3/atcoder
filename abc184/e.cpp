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

int dp[2020][2020];
constexpr int dh[] = {0, 0, 1, -1};
constexpr int dw[] = {1, -1, 0, 0};

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int h, w;
    string s[2020];
    vector<pii> warp[30];
    bool warped[30] = {};
    cin >> h >> w;
    s[0] = s[h + 1] = string(w + 2, '#');
    rep(hi, h) {
        string x;
        cin >> x;
        s[hi + 1] = "#" + x + "#";
    }

    h += 2, w += 2;

    rep(hi, h) rep(wi, w) {
        if ('a' <= s[hi][wi] && s[hi][wi] <= 'z') {
            warp[s[hi][wi] - 'a'].emplace_back(hi, wi);
        }
    }

    int sh, sw, gh, gw;
    rep(hi, h) rep(wi, w) {
            if (s[hi][wi] == 'S') sh = hi, sw = wi;
            if (s[hi][wi] == 'G') gh = hi, gw = wi;
    }

    rep(hi, h) rep(wi, w) dp[hi][wi] = -1;
    queue<pii> bfs;
    bfs.emplace(sh, sw);
    dp[sh][sw] = 0;
    while (!bfs.empty()) {
        const auto [hi, wi] = bfs.front();
        bfs.pop();
        rep(i, 4) {
            const int H = hi + dh[i], W = wi + dw[i];
            if (s[H][W] != '#' && dp[H][W] == -1) {
                dp[H][W] = dp[hi][wi] + 1;
                bfs.emplace(H, W);
            }
        }
        if ('a' <= s[hi][wi] && s[hi][wi] <= 'z' && !warped[s[hi][wi] - 'a']) {
            warped[s[hi][wi] - 'a'] = true;
            for (auto [H, W] : warp[s[hi][wi] - 'a']) {
                if (dp[H][W] == -1) {
                    dp[H][W] = dp[hi][wi] + 1;
                    bfs.emplace(H, W);
                }
            }
        }
    }

    print(dp[gh][gw]);

    return 0;
}

/*
  ___   ___ _ __  _ __
 / _ \ / __| '_ \| '_ \
|  __/| (__| |_) | |_) |
 \___(_)___| .__/| .__/
           |_|   |_|
*/
