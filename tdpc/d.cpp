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


double dp[2][61][39][27];

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 n, d;
    cin >> n >> d;

    int64 primes[3] = {2, 3, 5};
    int64 divs[3] = {0, 0, 0};

    rep(i, 3) {
        while (d % primes[i] == 0) {
            d /= primes[i];
            divs[i] += 1;
        }
    }

    if (d > 1) { print(0.0); return 0; }

    dp[0][0][0][0] = 1.;

    int p2 = divs[0], p3 = divs[1], p5 = divs[2];
    debug3(p2, p3, p5);

    rep(i, n) {
        int b = i & 1;
        rep(k2, p2 + 1) rep(k3, p3 + 1) rep(k5, p5 + 1) {
        double c = dp[b][k2][k3][k5];
        dp[b^1][k2][k3][k5] += c / 6.; // 1
        dp[b^1][min(p2, k2 + 1)][k3][k5] += c / 6.; // 2
        dp[b^1][k2][min(p3, k3 + 1)][k5] += c / 6.; // 3
        dp[b^1][min(p2, k2 + 2)][k3][k5] += c / 6.; // 4
        dp[b^1][k2][k3][min(p5, k5 + 1)] += c / 6.; // 5
        dp[b^1][min(p2, k2 + 1)][min(p3, k3 + 1)][k5] += c / 6.; // 6
        dp[b][k2][k3][k5] = 0.;
        }
    }

    print(dp[n & 1][p2][p3][p5]);

    return 0;
}

