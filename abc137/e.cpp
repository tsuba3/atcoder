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

    int n, m, p;
    int a[5100];
    int b[5100];
    int c[5100];
    cin >> n >> m >> p;
    rep(i, m) cin >> a[i] >> b[i] >> c[i];
    rep(i, m) a[i]--;
    rep(i, m) b[i]--;
    rep(i, m) c[i] = -(c[i] - p);

    int d[3000];
    fill(begin(d), begin(d) + 3000, INF);
    d[0] = 0;

    rep(i, n - 1) {
        rep(j, m) {
            if (d[b[j]] > d[a[j]] + c[j])
                d[b[j]] = d[a[j]] + c[j];
        }
    }

    int temp[3000];
    copy(begin(d), begin(d) + 3000, begin(temp));

    rep(i, n - 1) {
        rep(j, m) {
            if (d[b[j]] > d[a[j]] + c[j])
                d[b[j]] = d[a[j]] + c[j];
        }
    }

    ////////////////////////////////////

    vector<vector<int>> forward(n);
    vector<vector<int>> back(n);
    rep(i, m) {
        forward[a[i]].push_back(b[i]);
        back[b[i]].push_back(a[i]);
    }
        

    unordered_set<int> fs;
    unordered_set<int> bs;
    stack<int> dfs;
    vector<bool> visited(n);
    dfs.push(0);
    while (!dfs.empty()) {
        int u = dfs.top();
        dfs.pop();
        if (visited[u]) continue;
        visited[u] = true;
        fs.insert(u);
        for (auto it = forward[u].begin(); it < forward[u].end(); ++it) 
            dfs.push(*it);
    }

    dfs.push(n - 1);
    fill(all(visited), false);
    while (!dfs.empty()) {
        int u = dfs.top();
        dfs.pop();
        if (visited[u]) continue;
        visited[u] = true;
        bs.insert(u);
        for (auto it = back[u].begin(); it < back[u].end(); ++it)
            dfs.push(*it);
    }

    bool flag = false;
    for (auto it = fs.begin(); it != fs.end(); it++) {
        if (bs.find(*it) != bs.end()) {
            flag = flag || (d[*it] != temp[*it]);
        }
    }

    if (flag)
        print(-1);
    else
        print(max(0, -d[n - 1]));

    return 0;
}

