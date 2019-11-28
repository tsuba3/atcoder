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

    int n, q;
    int d[60][60];
    int p[2600];
    scanf("%d", &n);
    rep(i, n) rep(j, n) scanf("%d", &d[i][j]);
    scanf("%d", &q);
    rep(i, q) scanf("%d", &p[i]);

    int ds[60][60];
    memset(ds, 0, sizeof ds);

    // ds[j][i] := sum(d[:j, :i])
    rep(j, n) {
        int s = 0;
        rep(i, n) {
            ds[j + 1][i + 1] = ds[j][i + 1] + (s += d[j][i]);
        }
    }

    // rep(j, 10) { rep(i, 10) cerr << ds[j][i] << ' '; cerr << '\n';} {
    int ans[3000];
    memset(ans, 0, sizeof ans);

    for (int ja = 0; ja < n; ++ja) for (int jb = ja + 1; jb <= n; ++jb)
        for (int ia = 0; ia < n; ++ia) for (int ib = ia + 1; ib <= n; ++ib) {
            int x = (ib - ia) * (jb - ja);
            int t = ds[jb][ib] - ds[ja][ib] - ds[jb][ia] + ds[ja][ia];
            if (ans[x] < t) ans[x] = t;
        }


    // rep(i, 20) cerr << ans[i] << ' '; cerr << '\n';
    rep(i, n * n) if (ans[i + 1] < ans[i]) ans[i + 1] = ans[i]; 
    // rep(i, 20) cerr << ans[i] << ' '; cerr << '\n';

    rep(i, q) printf("%d\n", ans[p[i]]);

    return 0;
}

