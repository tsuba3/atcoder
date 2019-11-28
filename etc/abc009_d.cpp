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

    int k, M;
    unsigned int a[110], c[110];
    scanf("%d", &k);
    scanf("%d", &M);
    rep(i, k) scanf("%d", &a[i]);
    rep(i, k) scanf("%d", &c[i]);

    if (M <= k) {
        print(a[M - 1]);
        return 0;
    }

    // a3   |c1 c2 c3| a2
    // a2 = | 1  0  0| a1
    // a1   | 0  1  0| a0
    unsigned int m[31][110][110];
    memset(m, 0, sizeof(m));
    rep(i, k) m[0][0][i] = c[i];
    rep(i, k - 1) m[0][i + 1][i] = 1;
    rep(mi, 30) {
        rep(i, k) rep(l, k) rep(j, k) {
            m[mi + 1][i][j] ^= m[mi][i][l] & m[mi][l][j];
        }
    }

    unsigned int p = M - k;
    unsigned int mm[110][110];
    unsigned int t[110][110];
    memset(mm, 0, sizeof mm);
    rep(i, k) mm[i][i] = -1;
    rep(mi, 30) if (p & (1 << mi)) {
        memset(t, 0, sizeof t);
        rep(i, k) rep(l, k) rep(j, k) {
            t[i][j] ^= mm[i][l] & m[mi][l][j];
        }
        swap(mm, t);
    }

    debug(p);
    rep(i, k) { rep(j, k) cerr << mm[i][j] << ' '; cerr << '\n'; }

    unsigned int ans = 0;
    rep(i, k) ans ^= mm[0][i] & a[k - i - 1];
    print(ans);

    return 0;
}

