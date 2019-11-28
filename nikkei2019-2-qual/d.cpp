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

// End of template.

typedef struct {
    int l;
    int r;
    int64 c;
} LRC;

int64 dp[200100];
int64 sq[800];
const int N = 256;

void set_min(int64 x, int l, int r) {
    int L = (l >> 8) + 1;
    int R = r >> 8;
    int M = min(L << 8, r);
    for (int i = l; i < M; ++i) {
        if (dp[i] > x) dp[i] = x;
    }
    for (int i = R >> 8; i < r; ++i) {
        if (dp[i] > x) dp[i] = x;
    }
    for (int i = L; i < R; ++i) {
        if (sq[i] > x) sq[i] = x;
    }
}

int64 get_min(int l, int r) {
    int L = (l >> 8) + 1;
    int R = r >> 8;
    int M = min(L << 8, r);
    debug3(L, R, M);
    int64 res = INF64;
    for (int i = l; i < M; ++i) {
        if (res > dp[i]) res = dp[i];
    }
    for (int i = R >> 8; i < r; ++i) {
        if (res > dp[i]) res = dp[i];
    }
    for (int i = L; i < R; ++i) {
        if (res > sq[i]) res = sq[i];
    }
    return res;
}

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    LRC a[100100];
    scanf("%d %d", &n, &m);
    rep(i, m) {
        scanf("%d %d %lld", &a[i].l, &a[i].r, &a[i].c);
        a[i].l -= 1;
        a[i].r -= 1;
    }

    sort(begin(a), begin(a) + m, [](LRC x, LRC y) {return x.l < y.l;});
    fill(begin(dp), end(dp), INF64);
    fill(begin(sq), end(sq), INF64);
    dp[0] = 0;

    rep(i, m) {
        // [l, r) の最小値を求める
        debug(i);
        debug3(a[i].l, a[i].r, a[i].c);
        int64 tmin = get_min(a[i].l, a[i].r);
        debug(tmin);
        // [l, r] の最小値をtmin + cにする
        set_min(tmin + a[i].c, a[i].l, a[i].r + 1);
        rep(i, 10) cerr << dp[i] << ' '; cerr << '\n';
        cerr << '\n';
    }

    print(min(dp[n - 1], sq[(n - 1) >> 8]));

    return 0;
}

