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
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <chrono>
#include <random>

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
#ifdef ONLINE_JUDGE
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define dbg(v)
#else
#define debug(x) cerr << #x << ": " << (x) << '\n'
#define debug2(x, y) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'
#define dbg(v) for (size_t _ = 0; _ < v.size(); ++_){cerr << #v << "[" << _ << "] : " << v[_] << '\n';}
#endif

// constant
const int INF = (1<<30) - 1;
const int64 INF64 = (1LL<<62) - 1;

template<typename T> T gcd(T a, T b) {
    if (a < b) return gcd(b, a);
    T r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

template<typename T> T lcm(const T a, const T b) {
    return a / gcd(a, b) * b;
}

template<typename T> bool chmin(T& a, const T& b) {
    if (a > b) return a = b, true; else return false;
}

template<typename T> bool chmax(T& a, const T& b) {
    if (a < b) return a = b, true; else return false;
}

// End of template.

struct M {
    int64 m11, m12, m13, m21, m22, m23, m31, m32, m33;
};

struct V {
    int64 x, y, z;
};

M mul(M a, M b) {
    return M {
            a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31,
            a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32,
            a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33,

            a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31,
            a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32,
            a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33,

            a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31,
            a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32,
            a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33,
            };
}

V mul(M a, V b) {
    return V {
            a.m11 * b.x + a.m12 * b.y + a.m13 * b.z,
            a.m21 * b.x + a.m22 * b.y + a.m23 * b.z,
            a.m31 * b.x + a.m32 * b.y + a.m33 * b.z,
    };
}

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    int n, m, q;
    cin >> n;
    vector<V> v(n);
    rep(i, n) {
        cin >> v[i].x >> v[i].y;
        v[i].z = 1;
    }
    cin >> m;
    vector<M> op;
    op.reserve(m);
    rep(i, m) {
        int64 t, p;
        cin >> t;
        if (t == 2) {
            op.push_back(M{
                0, -1, 0,
                1,  0, 0,
                0,  0, 1,
            });
        } else if (t == 1) {
            op.push_back(M {
                0, 1, 0,
                -1, 0, 0,
                0, 0, 1,
            });
        } else if (t == 3) {
            cin >> p;
            op.push_back(M {
                -1, 0, 2 * p,
                0, 1, 0,
                0, 0, 1,
            });
        } else {
            cin >> p;
            op.push_back(M {
                1, 0, 0,
                0, -1, 2 * p,
                0, 0, 1,
            });
        }
    }

    vector<M> oped;
    oped.reserve(m + 1);
    oped.push_back(M{
        1, 0, 0,
        0, 1, 0,
        0, 0, 1,
    });
    for (M x : op) oped.push_back(mul(x, oped.back()));


    cin >> q;
    rep(qi, q) {
        int a, b;
        cin >> a >> b;
        a, b--;
        V ans = mul(oped[a], v[b]);
        print2(ans.x, ans.y);
    }


    return 0;
}

/*
  ___   ___ _ __  _ __
 / _ \ / __| '_ \| '_ \
|  __/| (__| |_) | |_) |
 \___(_)___| .__/| .__/
           |_|   |_|
*/
