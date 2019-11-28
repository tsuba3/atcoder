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

int64 mod = pow(10, 9) + 7;
int64 ans;

void P(int64 n, int64 m) {
    rep(i, m) ans = (ans * (n - i)) % mod;
}

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 n, k;
//    scanf("%lld %lld", &n, &k);
    cin >> n >> k;
    vector<vector<int>> adj(n);
    rep(i, n - 1) {
        int a, b;
        // scanf("%d %d", &a, &b);
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ans = k;
    stack<int> dfs;
    vector<bool> visited(n, false);
    dfs.push(0);
    int depth = 0;
    while(!dfs.empty()) {
        int x = dfs.top();
        dfs.pop();
        visited[x] = true;
        int cdepth = depth;

        int64 m = 0;
        for (auto v : adj[x]) {
            if (!visited[v]) {
                m++;
                dfs.push(v);
                depth++;
            } else {
                depth--;
            }
        }
        P(k - 1 - (cdepth == 0 ? 0 : 1), m);
        cerr << '\n';
    }


    cout << ans << '\n';

    return 0;
}

