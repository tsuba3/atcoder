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
// begin fast io

char buf[10000000], OUT[10000000];
int bufi = 0, outi = 0;

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

const char digit_pairs[] = {
        "00010203040506070809"
        "10111213141516171819"
        "20212223242526272829"
        "30313233343536373839"
        "40414243444546474849"
        "50515253545556575859"
        "60616263646566676869"
        "70717273747576777879"
        "80818283848586878889"
        "90919293949596979899"
};

template<typename T>
void writeui(T n) {
    if (n == 0) OUT[outi++] = '0';
    int size;
    if (n >= 1e12) {
        if (n >= 1e16) {
            if (n >= 1e18) {
                if (n >= 1e19) size = 20;
                else size = 19;
            } else {
                if (n >= 1e17) size = 18;
                else size = 17;
            }
        } else {
            if (n >= 1e14) {
                if (n >= 1e15) size = 16;
                else size = 15;
            } else {
                if (n >= 1e13) size = 14;
                else size = 13;
            }
        }
    } else if (n >= 1e4) {
        if (n >= 1e8) {
            if (n >= 1e10) {
                if (n >= 1e11) size = 12;
                else size = 11;
            } else {
                if (n >= 1e9) size = 10;
                else size = 9;
            }
        } else {
            if (n >= 1e6) {
                if (n >= 1e7) size = 8;
                else size = 7;
            } else {
                if (n >= 1e5) size = 6;
                else size = 5;
            }
        }
    } else {
        if (n >= 1e2) {
            if (n >= 1e3) size = 4;
            else size = 3;
        } else {
            if (n >= 1e1) size = 2;
            else size = 1;
        }
    }
    char *c = OUT + outi + size;
    outi += size;
    while (n >= 100) {
        int x = n % 100;
        n /= 100;
        *--c = digit_pairs[2 * x + 1];
        *--c = digit_pairs[2 * x];
    }
    while (n > 0) {
        *--c = '0' + (n % 10);
        n /= 10;
    }
}
// end fast io

template<typename T, int b = 8, int bit = sizeof(T) * 8>
void radix_sort(T *a, int n) {
    T temp[200200];
    T *dist = temp, *src = a;
    constexpr T mask = (1 << b) - 1;
    constexpr int kn = (bit + b - 1) / b;
    for (int k = 0; k < kn; ++k) {
        T bucket[1 << b] = {};
        T index[1 << b];
        for (int i = 0; i < n; ++i) bucket[mask & (src[i] >> (b * k))] += 1;
        index[0] = 0;
        for (int i = 0; i < (1 << b) - 1; ++i) index[i + 1] = index[i] + bucket[i];
        for (int i = 0; i < n; ++i) dist[index[mask & (src[i] >> (b * k))]++] = src[i];
        swap(dist, src);
    }
    if (kn % 2 == 1) {
        memcpy(a, src, sizeof(T) * n);
    }
}

struct A {
    int32_t v;
    int32_t idx;
};

int64 dp[2][2020];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること

    int n;
    A a[2020];
    readui(n);
    rep(i, n) a[i].idx = i, readui(a[i].v);
    radix_sort<int64_t, 8, 32>((int64_t*)a, n);
    reverse(begin(a), begin(a) + n);

    int64 ans = 0;

    // dp[x][y]: a[:x+y] のうち x 人を左から、y 人を右側から詰めた時の最大値
    for (int x = 0; x < n; ++x) {
        int X = x & 1;
        for (int y = 0; x + y < n; ++y) {
            chmax(dp[X ^ 1][y], dp[X][y] + (int64) a[x + y].v * abs(a[x + y].idx - x));
            chmax(dp[X][y + 1], dp[X][y] + (int64) a[x + y].v * abs(a[x + y].idx - (n - 1 - y)));
        }
        chmax(ans, dp[X][n - x]);
    }

    print(ans);


    return 0;
}

