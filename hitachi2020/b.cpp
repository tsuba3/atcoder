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
// begin fast io

char buf[10000000];
int bufi = 0;

template<typename T>
void readui(T &n) {
    n = 0;
    int c = buf[bufi++];
    for (; '0' <= c && c <= '9'; c = buf[bufi++])
        n = 10 * n + c - '0';
}

template<typename T>
void readi(T &n) {
    bool negative = false;
    if (buf[bufi] == '-') negative = true, bufi++;
    readui(n);
    if (negative) n = -n;
}

template<typename T>
void readuf(T &x) {
    x = 0;
    T y = 0;
    int z = 0;
    int c = buf[bufi++];
    for (; '0' <= c && c <= '9'; c = buf[bufi++])
        x = 10 * x + c - '0';
    if (buf[bufi - 1] == '.')
        for (; '0' <= c && c <= '9'; c = buf[bufi++], ++z)
            y = 10 * y + c - '0';
    x += y / pow(10, z);
}

template<typename T>
void readf(T &x) {
    bool negative = false;
    if (buf[bufi] == '-') negative = true, bufi++;
    readuf(x);
    if (negative) x = -x;
}

void reads(string &s) {
    const int begin = bufi;
    int c;
    while (c = buf[bufi++], c != ' ' && c != '\n') {}
    s = string(buf + begin, buf + bufi);
}

void readline(string &s) {
    const int begin = bufi;
    while (buf[bufi++] != '\n') {}
    s = string(buf + begin, buf + bufi);
}

// end fast io



int A, B, M, a[100100], b[100100];

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int temp = INF;
    int mina = INF, minb = INF;

    readui(A), readui(B), readui(M);
    rep(i, A) readui(a[i]), chmin(mina, a[i]);
    rep(i, B) readui(b[i]), chmin(minb, b[i]);
    chmin(temp, mina + minb);
    rep(i, M) {
        int x, y, c;
        readui(x), readui(y), readui(c);
        chmin(temp, a[x - 1] + b[y - 1] - c);
    }

    print(temp);

    return 0;
}

