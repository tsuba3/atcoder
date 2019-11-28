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

#define U 0
#define D 1
#define L 2
#define R 3
#define Y (y >= n ? y - n : y)
#define X (x >= n ? x - n : x)

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
const char dc[4] = {'R', 'L', 'D', 'U'};

int main(){
    int n, M, B;
    int gy, gx;
    // int r[40][40];
    int ry[100], rx[100], rd[100];
    bool b[40][40];
    // memset(r, 0, sizeof r);
    memset(b, 0, sizeof b);
    scanf("%d %d %d", &n, &M, &B);
    scanf("%d %d", &gx, &gy);
    rep(i, M) {
        char c;
        scanf("%d %d %c", &rx[i], &ry[i], &c);
        if ( c == 'U' ) rd[i] = U;
        else if ( c == 'D' ) rd[i] = D;
        else if ( c == 'L' ) rd[i] = L;
        else if ( c == 'R' ) rd[i] = R;
    }
    rep(i, B) {
        int y, x;
        scanf("%d %d", &y, &x);
        b[x][y] = true;
    }

    // d[D][y1][x1] (x1, y1) から D 方向へ何ます進めるか
    int d[4][40][40];
    rep(y, n) {
        int t = 0;
        rep(x, 2 * n) {
            if (b[y][X]) t = d[L][y][X] = 0;
            else d[L][y][X] = t++;
        }
    }
    rep(y, n) {
        int t = 0;
        for(int x = 2 * n - 1; x >= 0; --x) {
            if (b[y][X]) t = d[R][y][X] = 0;
            else d[R][y][X] = t++;
        }
    }
    rep(x, n) {
        int t = 0;
        rep(y, 2 * n) {
            if (b[Y][x]) t = d[U][Y][x] = 0;
            else d[U][Y][x] = t++;
        }
    }
    rep(x, n) {
        int t = 0;
        for (int y = 2 * n - 1; y >= 0; --y) {
            if (b[Y][x]) t = d[D][Y][x] = 0;
            else d[D][Y][x] = t++;
        }
    }
    rep(di, 4) rep(y, n) rep(x, n) if (d[di][x][y] >= n) d[di][x][y] = n - 1;
    rep(y, n) {rep(x, n) fprintf(stderr, "%2d ", d[U][x][y]); cerr << '\n';} cerr << "\n\n";
    rep(y, n) {rep(x, n) fprintf(stderr, "%2d ", d[D][x][y]); cerr << '\n';} cerr << "\n\n";
    rep(y, n) {rep(x, n) fprintf(stderr, "%2d ", d[L][x][y]); cerr << '\n';} cerr << "\n\n";
    rep(y, n) {rep(x, n) fprintf(stderr, "%2d ", d[R][x][y]); cerr << '\n';} cerr << "\n\n";


    int dg[40][40];
    fill(begin(dg[0]), begin(dg[0]) + 1600, -1);
    dg[gy][gx] = 0;
    int dd[40][40];
    memset(dd, -1, sizeof dd);
    int dl[40][40];
    memset(dl, -1, sizeof dl);
    queue<pii> que;
    que.push(make_pair(gx, gy));
    while (!que.empty()) {
        pii xy = que.front();
        que.pop();
        for(int l = 1; l <= d[U][xy.second][xy.first]; ++l) {
            int y = n + xy.second - l;
            y = Y;
            int x = xy.first;
            if (dg[y][x] == -1) {
                dg[y][x] = dg[xy.second][xy.first] + 1;
                dd[y][x] = U;
                dl[y][x] = l;
                que.push(make_pair(x, y));
            }
        }
        for(int l = 1; l <= d[D][xy.second][xy.first]; ++l) {
            int y = xy.second + l;
            y = Y;
            int x = xy.first;
            if (dg[y][x] == -1) {
                dg[y][x] = dg[xy.second][xy.first] + 1;
                dd[y][x] = D;
                dl[y][x] = l;
                que.push(make_pair(x, y));
            }
        }
        for(int l = 1; l <= d[L][xy.second][xy.first]; ++l) {
            int y = xy.second;
            int x = n + xy.first - l;
            x = X;
            if (dg[y][x] == -1) {
                dg[y][x] = dg[xy.second][xy.first] + 1;
                dd[y][x] = L;
                dl[y][x] = l;
                que.push(make_pair(x, y));
            }
        }
        for(int l = 1; l <= d[R][xy.second][xy.first]; ++l) {
            int y = xy.second;
            int x = xy.first + l;
            x = X;
            if (dg[y][x] == -1) {
                dg[y][x] = dg[xy.second][xy.first] + 1;
                dd[y][x] = R;
                dl[y][x] = l;
                que.push(make_pair(x, y));
            }
        }
    }
    cerr << "dg\n";
    rep(y, n) {rep(x, n) fprintf(stderr, "%2d ", dg[x][y] == INF ? -1 : dg[x][y]); cerr << '\n';} cerr << "\n\n";
    cerr << "dl\n";
    rep(y, n) {rep(x, n) fprintf(stderr, "%2d ", dl[x][y]); cerr << '\n';} cerr << "\n\n";
    cerr << "dd\n";
    rep(y, n) {rep(x, n) fprintf(stderr, " %c ", dl[x][y] == -1 ? '.' : dc[dd[x][y]]); cerr << '\n';} cerr << "\n\n";
    cerr << "dg dd\n";
    rep(y, n) {rep(x, n) fprintf(stderr, "%2d%c ", dg[x][y] == INF ? -1 : dg[x][y], dl[x][y] == -1 ? '.' : dc[dd[x][y]]); cerr << '\n';} cerr << "\n\n";



    int ans[40][40];
    memset(ans, -1, sizeof ans);

    /*
    rep(ri, M) {
        int md = INF; int mll = -1;
        for (int l = d[rd[ri]][ry[ri]][rx[ri]]; l >= 0; --l) {
            int x = rx[ri] + dx[rd[ri]] * l;
            int y = ry[ri] + dy[rd[ri]] * l;
            x %= n;
            y %= n;
            
            int cd = dg[y][x];
            if (cd < md) {
                md = cd;
                mll = l;
            }
        }
        int x = (rx[ri] + dx[rd[ri]] * mll) % n;
        int y = (ry[ri] + dy[rd[ri]] * mll) % n;
        int cd = rd[ri];
        while(md > 0) {
            ans[y][x] = cd = dd[y][x];
            x += dx[cd] * dl[y][x];
            y += dy[cd] * dl[y][x];
            x %= n;
            y %= n;
            md--;
        }
    }*/
    /*rep(ri, M) {
        int x = rx[ri];
        int y = ry[ri];
        int cd = dd[y][x];
        bool debug = y == 13 && x == 23;
        if (debug) debug3(x, y, dc[cd]);
        rep (i, dg[y][x] + 1) {
            ans[y][x] = cd = dd[y][x];
            x += dx[cd] * (dl[y][x]);
            y += dy[cd] * (dl[y][x]);
            x %= n;
            y %= n;
            if (debug) debug2(x, y);
        }
    }*/
    rep(y, n) rep(x, n) ans[y][x] = dd[y][x];

    bool need[40][40];
    memset(need, false, sizeof need);
    rep(ri, M) {
        int x = rx[ri] % n;
        int y = ry[ri] % n;
        int cd = rd[ri];
        if (ans[y][x] == -1) continue;
        //while (gx != x && gy != y) {
        rep(i, 1000) {
            debug2(x, y);
            if (ans[y][x] == -1) break;
            if (ans[y][x] != cd) need[y][x] = true;
            cd = ans[y][x];
            x += n + dx[cd];
            y += n + dy[cd];
            x %= n;
            y %= n;
        }
    }

    rep(y, n) {rep(x, n) fprintf(stderr, "%c ", ans[x][y] != -1 ? dc[ans[x][y]] : '.'); cerr << '\n';} cerr << "\n\n";


    vector<pii> ansxy;
    ansxy.reserve(100);
    rep(y, n) rep(x, n) if (ans[y][x] != -1 && need[y][x]) {
        ansxy.push_back(make_pair(x, y));
    }

    print(ansxy.size());
    rep(i, ansxy.size()) {
        int x = ansxy[i].first;
        int y = ansxy[i].second;
        print3(x, y, dc[ans[y][x]]);
    }


    return 0;
}

