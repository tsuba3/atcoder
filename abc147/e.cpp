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

#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx")

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

char buf[40000];
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

constexpr int N = 80*80;

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    measure_time();

    cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    measure_time();

    int h, w, a[81][81] = {};
    readi(h); readi(w);
    rep(hi, h) rep(wi, w) readi(a[hi][wi]);
    rep(hi, h) rep(wi, w) {
        int x;
        readi(x);
        a[hi][wi] -= x;
        if (a[hi][wi] < 0) a[hi][wi] *= -1;
    }

    measure_time();

    bitset<2*N> dp[81];
    bitset<N> dp0[81];
    dp0[0][N/2] = true;
    rep(hi, h) {
        for (int wi = hi; wi >= 0; --wi) {
            dp[wi + 1] |= (dp[wi] << a[hi][wi]) | (dp[wi] >> a[hi][wi]);
        }
    }

    rep(i, (sizeof dp) / (sizeof dp[0])) {
        memcpy(((char*) &dp[i]) + N / 2 / 8, &dp0[i], N / 8);
    }

    measure_time();

    const auto& ans = dp[w];
    rep(i, N) {
        if (ans.test(N + i) || ans.test(N - i)) {
            print(i);
            break;
        }
    }

    measure_time();
    print_time();
    return 0;
}


