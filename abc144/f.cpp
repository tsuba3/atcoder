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
int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    vector<int> st[2000];
    scanf("%d %d", &n, &m);
    rep(i, m) {
        int s, t;
        scanf("%d %d", &s, &t);
        s--;
        t--;
        st[s].push_back(t);
    }


    double dp[610];
    dp[n - 1] = 0.0;
    for (int i = n - 2; i >= 0; --i) {
        double s = 0;
        rep(j, st[i].size()) s += dp[st[i][j]] + 1;
        dp[i] = s / st[i].size();
    }

    double tmin = dp[0];

    rep(k, n) {
        for (int i = n - 2; i >= 0; --i) if (i != k || st[k].size() <= 1) {
            double s = 0;
            rep(j, st[i].size()) s += dp[st[i][j]] + 1;
            dp[i] = s / st[i].size();
        } else {
            double s = 0;
            double tmax = 0;
            rep(j, st[i].size()) {
                s += dp[st[i][j]] + 1;
                tmax = max(tmax, dp[st[i][j]] + 1);
            }
            dp[i] = (s - tmax) / (st[i].size() - 1);
        }
        tmin = min(tmin, dp[0]);
    }

    print(tmin);

    return 0;
}

