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

////////////////////////////////////////////////////////////////////

string s, t;

int main(){
    cout << fixed << setprecision(15);

    cin >> s >> t;
    int n = s.length();
    s = s + s;

    int64 res = 0;

    vector<vector<int> > position(26);
    rep(i, 2*n) {
        position[int(s[i] - 'a')].push_back(i);
    }

    dbg(position['s' - 'a']);

    int pre = -1;
    rep(i, t.length()) {
        if (position[int(t[i] - 'a')].size() == 0) {
            cout << -1 << '\n';
            return 0;
        }
        auto it = upper_bound(all(position[int(t[i] - 'a')]), pre);
        int x = *it;
        debug(x);
        res += x - pre;
        pre = x % n;
        debug(pre); debug(res);
    }
    
    cout << res << '\n';

    return 0;
}

