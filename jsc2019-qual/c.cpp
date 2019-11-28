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

int64 n;
string s;
int64 mod = 1000000007;
int64 ans = 1;

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;


    // ans = n!/
    for (int64 i = 2; i <= n; ++i) { ans *= i; ans %= mod; }

    int wc = 0; rep(i, 2*n) if (s[i] == 'B') wc++;
    if (s[0] == 'W' || s[2*n - 1] == 'W' || wc % 2 != 0) {
        cout << "0\n";
        return 0;
    }

    int64 sum[100100];
    sum[0] = 0;
    rep(i, 2*n) sum[i+1] = sum[i] + ((s[i] == (i % 2 == 0 ? 'W' : 'B') )? 1:0);
    for (int64 i = 0; i < n; ++i) {
        if (i % 2 == 0)
            ans *= (sum[2*n - i+1] - sum[i]);
        else
            ans *= 1 + (2*n - 2*i) - (sum[2*n - i+1] - sum[i]);
        ans %= mod;
    }


    cout << ans << '\n';

    return 0;
}

