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

    int n, m;
    cin >> n >> m;
    vector<int> adj[1010];
    int mat[1010][1010];
    rep(mi, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mat[a][b] = 1;
        mat[b][a] = -1;

        adj[a].push_back(b);
    }

    rep(start, n) {
        bool visited[1010];
        memset(visited, 0, 1010);
        queue<int> q;
        debug(start);
        q.push(start);
        int c = 0;
        vector<int> vec;
        while (!q.empty()) {
            int x = q.front();
            vec.push_back(x);
            debug(x);
            q.pop();
            if (c > 0 && x == start) {
                // TODO
                vector<int> vi;
                rep(i, n) if (visited[i]) vi.push_back(i);
                if (vi.size() == 1) break;
                bool flag = false;
                for (int i = 0; i < vi.size(); ++i) {
                    if (adj[i].size() != 1) {flag = true; break;}
                }
                if (flag == false) {
                    print(vi.size());
                    rep(i, vi.size()) print(vi[i]);
                    return 0;
                }
            }
            else if (visited[x]) break;
            visited[x] = true;
            rep(v, adj[x].size()) q.push(adj[x][v]);
            c++;
        }
    }
    
    print(-1);

    return 0;
}

