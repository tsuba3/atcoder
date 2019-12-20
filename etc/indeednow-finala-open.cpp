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

// 3. 最適化 11ms -> 11ms
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

char buf[2000000];
int bufi = 0;
template<typename T>
void readi(T &n) {
    int c;
    n = 0;
    c = buf[bufi++];
    for (; '0' <= c && c <= '9'; c = buf[bufi++])
        n = 10 * n + c - '0';
}

char wbuf[600000];
int wbufi = 0;
template<typename T>
void writeui(T n) {
    if (n == 0) {
        wbuf[wbufi++] = '0', wbuf[wbufi++] = '\n';
        return ;
    }
    char temp[16];
    char* p = end(temp);
    while (n) {
        *--p = (n % 10) + '0';
        n /= 10;
    }
    while (p < end(temp))
        wbuf[wbufi++] = *p++;
    wbuf[wbufi++] = '\n';
}

// End of template.

template<typename T>
void chmax(T& a, const T& b) {
    if (a < b) a = b;
}

int dp[101][101][101];

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 1. 入力高速化　36ms -> 14ms
    cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int n, m;
    readi(n);
    readi(m);
    rep(i, n) {
        int a, b, c, w;
        readi(a);
        readi(b);
        readi(c);
        readi(w);
        chmax(dp[a][b][c], w);
    }
    // 4. if 文をループ内から削除 11ms -> 10ms
    for (int i = 0; i < 101; ++i) for (int j = 0; j < 101; ++j) {
        if(i) {
            chmax(dp[i][j][0], dp[i - 1][j][0]);
            chmax(dp[i][0][j], dp[i - 1][0][j]);
            chmax(dp[0][i][j], dp[0][i - 1][j]);
        }
        if (j) {
            chmax(dp[i][j][0], dp[i][j - 1][0]);
            chmax(dp[i][0][j], dp[i][0][j - 1]);
            chmax(dp[0][i][j], dp[0][i][j - 1]);
        }
    }
    for (int i = 1; i < 101; ++i) for (int j = 1; j < 101; ++j) for (int k = 1; k < 101; ++k) {
        chmax(dp[i][j][k], dp[i - 1][j][k]);
        chmax(dp[i][j][k], dp[i][j - 1][k]);
        chmax(dp[i][j][k], dp[i][j][k - 1]);
    }
    rep(i, m) {
        int x, y, z;
        readi(x);
        readi(y);
        readi(z);
        writeui(dp[x][y][z]);
    }

    cout.write(wbuf, wbufi);
    return 0;
}

