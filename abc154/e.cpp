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

template<typename T> bool chmin(T& a, const T& b) {
    if (a > b) return a = b, true; else return false;
}

template<typename T> bool chmax(T& a, const T& b) {
    if (a < b) return a = b, true; else return false;
}

// End of template.
// begin fast io

char buf[200];
int bufi = 0;

template<typename T>
void readui(T &n) {
    n = 0;
    int c = buf[bufi++];
    for (; '0' <= c && c <= '9'; c = buf[bufi++])
        n = 10 * n + c - '0';
}

// end fast io


int64 C(int64 n, int64 r) {
    if (n < r) return 0;
    int64 ans = 1;
    rep(i, r) {
        ans *= n - i;
        ans /= i + 1;
    }
    return ans;
}

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    constexpr char* n = buf;
    int d = 0;
    int k;

    while (buf[bufi] != '\n') {buf[bufi++] -= '0';}
    d = bufi;
    bufi++;
    readui(k);

    int dp0[100][4] = {}, dp1[100][4] = {};
    dp1[0][0] = 1;

    rep(i, d) {
        if (n[i] == 0) {
            rep(j, 3) dp0[i + 1][j] = dp0[i][j]; // 0
            rep(j, 3) dp0[i + 1][j + 1] = 9 * dp0[i][j]; // 1-9
            rep(j, 3) dp1[i + 1][j] += dp1[i][j]; // 0
            rep(j, 3) dp1[i + 1][j + 1] += 9 * dp1[i][j]; // 1-9
        } else {
            rep(j, 3) dp0[i + 1][j] += dp0[i][j] + dp1[i][j]; // 0
            rep(j, 3) dp0[i + 1][j + 1] += (n[i] - 1) * (dp0[i][j] + dp1[i][j]); // 1-(n[i]-1)
            rep(j, 3) dp1[i + 1][j + 1] += dp1[i][j]; // n[i]
            rep(j, 3) dp0[i + 1][j + 1] += dp0[i][j]; // n[i]
        }
    }

    rep(i, d + 1) rep(k, 4) debug3(i, k, dp0[i][k]);
    rep(i, d + 1) rep(k, 4) debug3(i, k, dp1[i][k]);

    print(dp0[d][k] + dp1[d][k]);

    return 0;
}

