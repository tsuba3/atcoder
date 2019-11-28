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


int n;
vector<pii> p;
const double pi = 3.141592653589793;
const double pi2 = pi / 2.0;

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    p.reserve(n);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }

    int a = 0, b = 0, c = 0;

    vector<double> rad(2 * n - 2);
    rep(i, n) {
        int x0 = p[i].first;
        int y0 = p[i].second;

        int radi = 0;
        rep (j, n) if (i != j) {
            rad[radi++] = atan2(p[j].first - x0, p[j].second - y0);
        }
        sort(rad.begin(), rad.begin() + (n - 1));
        rep(j, n - 1) rad[j + n - 1] = rad[j] + 2 * pi;
        dbg(rad);

        int l = 0, r = 1;
        int m90 = (n - 1) * (n - 2) / 2;
        // Count PI/2 rad
        while (l < n - 1 && r < 2 * n - 2) {
            double d = rad[r] - rad[l];
            debug3(l, r, d);
            if (pi2 + 1e-7 < d) {
                l += 1;
            } else if (d < pi2 - 1e-7) {
                r += 1;
                if (r - l >= n - 1) l += 1;
            } else {
                b += 1;
                r += 1;
            }
        }
    }

    a = n * (n - 1) * (n - 2) / 6 - b - c;
    print3(a, b, c);
    

    return 0;
}

