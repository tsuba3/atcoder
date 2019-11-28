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

#define pi 3.14159265358979323846264338327950288
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
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

int64 sq(int64 x) {return x * x;} 
struct vec {
    int64 x;
    int64 y;
    double r;
    double t;
};


int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vec v[210];
    cin >> n;
    rep(i, n) {
        cin >> v[i].x >> v[i].y;
        v[i].r = sqrt(sq(v[i].x) + sq(v[i].y));
        if (v[i].x == 0 && v[i].y == 0)
            v[i].t = 0.0;
        else
            v[i].t = atan2(v[i].x, v[i].y);
    }

    sort(begin(v), begin(v) + n, [](vec a, vec b) {return a.t  < b.t;});
    copy(begin(v), begin(v) + n, begin(v) + n);
    rep(i, n) v[n + i].r = v[i].r + 2.0 * pi;

    double temp = 0.0;

    int64 xsum[210];
    int64 ysum[210];
    xsum[0] = ysum[0] = 0;
    rep(i, 2 * n) xsum[i + 1] = xsum[i] + v[i + 1].x;
    rep(i, 2 * n) ysum[i + 1] = ysum[i] + v[i + 1].y;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= 2 * n && j - i <= n; ++j) {
            double r = sqrt(sq(xsum[j] - xsum[i]) + sq(ysum[j] - ysum[i]));
            if (temp < r) temp = r;
        }
    }

    print(temp);

    return 0;
}

