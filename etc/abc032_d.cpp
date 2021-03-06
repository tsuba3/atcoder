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

chrono::high_resolution_clock::time_point step_time[10];
int step_time_i = 0;
void measure_time() {
    step_time[step_time_i++] = chrono::high_resolution_clock::now();
}
double calc_microsecond(const chrono::high_resolution_clock::time_point &a, const chrono::high_resolution_clock::time_point &b) {
    return chrono::duration_cast<chrono::microseconds>(b - a).count() / 1000.0;
}
void print_time() {
    if (step_time_i < 2) return;
    fprintf(stderr, "Time: ");
    if (step_time_i > 2)
        fprintf(stderr, "%.3f ", calc_microsecond(step_time[0], step_time[step_time_i-1]));
    rep(i, step_time_i - 1)
        fprintf(stderr, "%.3f ", calc_microsecond(step_time[i], step_time[i+1]));
    fprintf(stderr, "\n");
}

char buf[1000*1000];
int bufi = 0;
template<typename T>
void readi(T &n) {
    bool negative = false;
    int c;
    n = 0;
    c = buf[bufi++];
    if (c == '-') negative = true, c = buf[bufi++];
    for (; '0' <= c && c <= '9'; c = buf[bufi++])
        n = 10 * n + c - '0';
    if (negative) n = -n;
}

// End of template.

template<typename T> void chmax(T& x, const T& y) { if (x < y) x = y; }
template<typename T> void chmin(T& x, const T& y) { if (x > y) x = y; }

pll dp[1 << 15 + 10];
int64 dp0[200 * 1000 + 10];

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int64 n, W, maxv = 0, maxw = 0;
    int64 v[200], w[200];
    cin >> n >> W;
    rep(i, n) {
        cin >> v[i] >> w[i];
        chmax(maxv, v[i]);
        chmax(maxw, w[i]);
    }

    if (n <= 30) {
        int64 ans = 0;
        auto dp_begin = begin(dp);
        auto dp_end = begin(dp) + (1 << (n / 2));

        rep(bits, 1 << (n / 2)) {
            rep(i, n / 2) if (bits & (1 << i)) {
                dp[bits].first += v[i];
                dp[bits].second += w[i];
            }
        }
        sort(dp_begin, dp_end, [](const auto a, const auto b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        });
        dp_end = unique(dp_begin, dp_end, [](const auto& a, const auto& b) {
            return a.second == b.second;
        });
        rep(i, dp_end - dp_begin - 1) chmax(dp[i + 1].first, dp[i].first);

        rep(bits, 1 << (n - n / 2)) {
            int64 vv = 0, ww = 0;
            rep(i, n - n / 2) if (bits & (1 << i)) {
                vv += v[i + n / 2];
                ww += w[i + n / 2];
            }
            auto it = partition_point(dp_begin, dp_end, [&ww, &W](const auto& x) {return x.second + ww <= W;});
            if (it > dp_begin)
                chmax(ans, vv + (it - 1)->first);
        }
        print(ans);
    } else if (maxw <= 1000) {
        rep(i, n) {
            for (int j = min(W, n * maxw); j >= w[i]; --j) {
                chmax(dp0[j], dp0[j - w[i]] + v[i]);
            }
        }
        print(dp0[min(W, n * maxw)]);
    } else { // maxv <= 1000
        fill(begin(dp0) + 1, begin(dp0) + n * maxv + 1, INF64);
        rep(i, n) {
            for (int j = n * maxv - v[i]; j >= 0; --j) {
                chmin(dp0[j + v[i]], dp0[j] + w[i]);
            }
        }
        int ans = 0;
        rep(i, n * maxv + 1) if (dp0[i] <= W) chmax(ans, i);
        print(ans);
    }


    return 0;
}

