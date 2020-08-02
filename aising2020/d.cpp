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

int f(int x) {
    int cnt = 0;
    while (x > 0) x %= __builtin_popcount(x), cnt += 1;
    return cnt;
}

int64 powmod(int64 x, int64 mod) {
    int64 res = 1, base = 2;
    while (x) {
        if (x & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        x >>= 1;
    }
    return res;
}

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int n;
    string x;
    cin >> n >> x;

    reverse(x.begin(), x.end());
    int popcnt = 0;
    rep(i, n) if (x[i] == '1') popcnt += 1;

    if (popcnt == 0) {
        print(1);
        return 0;
    }

    int64 csp = 0, csm = 0;
    int64 bp = 1, bm = 1;
    rep(i, n) {
        csp = (csp + (x[i] - '0') * bp) % (popcnt + 1);
        bp = (bp * 2) % (popcnt + 1);
        if (popcnt > 1) {
            csm = (csm + (x[i] - '0') * bm) % (popcnt - 1);
            bm = (bm * 2) % (popcnt - 1);
        }
    }

    debug3(popcnt, csm, csp);

    for (int i = n - 1; i >= 0; --i) {
        if (popcnt == 1 && x[i] == '1') {
            print(0);
            continue;
        }
        int64 X;
        if (x[i] == '1') { // 1 -> 0
            X = csm - powmod(i, popcnt - 1);
            X += popcnt - 1;
            X %= popcnt - 1;
        } else {
            X = csp + powmod(i, popcnt + 1);
            X += popcnt + 1;
            X %= popcnt + 1;
        }
        debug(X);
        print(f(X) + 1);
    }


    return 0;
}

/*
     _
  __| |  ___ _ __  _ __
 / _` | / __| '_ \| '_ \
| (_| || (__| |_) | |_) |
 \__,_(_)___| .__/| .__/
            |_|   |_|
*/
