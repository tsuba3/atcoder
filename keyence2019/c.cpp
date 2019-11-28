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
#include <map>
#include <set>

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
#define debug(x) cerr << #x << ": " << (x) << '\n'
#define dbg(v) for (size_t _ = 0; _ < v.size(); ++_){cerr << #v << "[" << _ << "] : " << v[_] << '\n';}
// constant
const int INF = (1<<30) - 1;
const int64 INF64 = (1LL<<62) - 1;

int n;
int64 a[100100];
int64 b[100100];
int64 sub[100100];

int main(){
    cout << fixed << setprecision(15);

    cin >> n;
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        cin >> b[i];
    }

    int64 suma = accumulate(begin(a), begin(a) + n, 0LL);
    int64 sumb = accumulate(begin(b), begin(b) + n, 0LL);

    if(suma < sumb) {
        cout << "-1\n";
        return 0;
    }

    rep(i, n) {
        sub[i] = a[i] - b[i];
    }

    sort(begin(sub), begin(sub) + n);

    int64 ans = 0;
    int64 m = 0;
    rep(i, n) {
        if (sub[i] >= 0)
            break;
        m -= sub[i];
        ans++;
    }

    for (int i = n - 1; i >= 0 && m > 0; i--) {
        m -= sub[i];
        ans++;
    }

    cout << ans << '\n';

    return 0;
}

