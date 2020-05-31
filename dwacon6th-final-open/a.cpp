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

string ans[3];

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int h, w;
    cin >> h >> w;
    bool trans = false, ok = true;
    if (w > h) {
        swap(w, h);
        trans = true;
    }
    if (h == 3 && w == 3) {
        ans[0] = "255";
        ans[1] = "252";
        ans[2] = "552";
    } else if (h >= 3 && w >= 3) {
        ok = false;
    } else if (w == 2 && h % 7 == 0) {
        rep(i, h / 7) ans[0] += "2555255";
        rep(i, h / 7) ans[1] += "2552555";
    } else if (w == 2 && h % 7 == 1) {
        rep(i, h / 7) ans[0] += "2555255";
        rep(i, h / 7) ans[1] += "2552555";
        ans[0] += "2";
        ans[1] += "2";
    } else if (w == 2 && h % 7 == 6) {
        ans[0] += "555255";
        ans[0] += "555255";
        rep(i, h / 7) ans[0] += "2555255";
        rep(i, h / 7) ans[1] += "2552555";
    } else if (w == 1) {
        rep(i, h / 7) ans[0] += "2255555";
        if (h % 7 == 0) {}
        else if (h % 7 == 2) ans[0] += "22";
        else if (h % 7 == 5) ans[0] = "55555" + ans[0];
        else ok = false;
    } else {
        ok = false;
    }

    if (!ok) {
        print("No");
    } else if (trans) {
        print("Yes");
        rep(wi, w) print(ans[wi]);
    } else {
        print("Yes");
        rep(hi, w) {
            rep(wi, h) {
                cout << ans[hi][wi];
            }
            cout << '\n';
        }
    }

    return 0;
}

