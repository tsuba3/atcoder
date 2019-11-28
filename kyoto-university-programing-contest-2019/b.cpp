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

    int n, m, W;
    int w[110];
    int v[110];
    vector<int> adj[5050];
    cin >> n >> m >> W;
    rep(i, n) cin >> w[i] >> v[i];
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pii> wv;
    bool visited[110];
    memset(visited, 0, sizeof(visited));

    rep(i, n) if (!visited[i]) {
        stack<int> dfs;
        dfs.push(i);
        int ww = 0, vv = 0;
        while (!dfs.empty()) {
            int x = dfs.top();
            visited[x] = true;
            dfs.pop();
            ww += w[x];
            vv += v[x];
            rep(j, adj[x].size()) {
                if (!visited[adj[x][j]]) dfs.push(adj[x][j]);
            }
        }
        wv.push_back(make_pair(ww, vv));
    }

    int dp[2][10010];
    memset(dp, 0, sizeof(dp));
    rep(i, wv.size()) {
        rep(wi, W + 1) {
            if (wi >= wv[i].first)
                dp[(i + 1) & 1][wi] = max(dp[i & 1][wi - wv[i].first] + wv[i].second, dp[i & 1][wi]);
            else
                dp[(i + 1) & 1][wi] = dp[i & 1][wi];
        }
    }

    cout << dp[wv.size() & 1][W] << '\n';

    return 0;
}

