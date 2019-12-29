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

template<typename T>
void chmin(T &a, const T &b) { if (a > b) a = b; }

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int n;
    int c[200200];
    int q;
    int nmin[2] = {INF, INF};
    int nminus[2] = {0, 0};
    cin >> n;
    int nn[2] = {n / 2 + (n & 1), n / 2};
    rep(i, n) {
        cin >> c[i];
        chmin(nmin[i & 1], c[i]);
    }
    cin >> q;

    int64 ans = 0;

    rep(qi, q) {
        int64 qt, x, a;
        cin >> qt;
        if (qt == 1) {
            cin >> x >> a;
            x--;
            if (c[x] - nminus[x & 1] >= a) {
                c[x] -= a;
                ans += a;
                chmin(nmin[x & 1], c[x]);
            }
        } else if (qt == 2) {
            cin >> a;
            if (nmin[0] - nminus[0] >= a) {
                nminus[0] += a;
                ans += a * nn[0];
            }
        } else if (qt == 3) {
            cin >> a;
            if (nmin[0] - nminus[0] >= a && nmin[1] - nminus[1] >= a) {
                nminus[0] += a;
                nminus[1] += a;
                ans += a * n;
            }
        }
    }
    
    print(ans);

    return 0;
}

