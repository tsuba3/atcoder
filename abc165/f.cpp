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
#define debug(x) cerr << #x << ": " << (x) << '\n'
#define debug2(x, y) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'
#define dbg(v) for (size_t _ = 0; _ < v.size(); ++_){cerr << #v << "[" << _ << "] : " << v[_] << '\n';}
// constant
const int INF = (1 << 30) - 1;
const int64 INF64 = (1LL << 62) - 1;

template<typename T>
T gcd(T a, T b) {
    if (a < b) return gcd(b, a);
    T r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

template<typename T>
T lcm(const T a, const T b) {
    return a / gcd(a, b) * b;
}

template<typename T>
bool chmin(T &a, const T &b) {
    if (a > b) return a = b, true; else return false;
}

template<typename T>
bool chmax(T &a, const T &b) {
    if (a < b) return a = b, true; else return false;
}

// End of template.

vector<int> vec[200200];
int a[200200];
int arr[200200];
int ans[200200];

void dfs(int i, int p) {
    const auto it = lower_bound(begin(arr), end(arr), a[i]);
    int x = it - begin(arr);
    int hist = arr[x];
    arr[x] = a[i];
    ans[i] = lower_bound(begin(arr), end(arr), INF) - begin(arr);
    for (int j : vec[i]) if (j != p) {
        dfs(j, i);
    }
    arr[x] = hist;
}

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    fill(begin(arr), end(arr), INF);
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    dfs(0, -1);
    rep(i, n) print(ans[i]);

    return 0;
}

