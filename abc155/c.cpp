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

char buf[5000000];
char out[5000000];
int bufi = 0;

template<typename T>
void readui(T &n) {
    n = 0;
    int c = buf[bufi++];
    for (; '0' <= c && c <= '9'; c = buf[bufi++])
        n = 10 * n + c - '0';
}
// end fast io

template< typename T, int b = 8, int bit = sizeof(T) * 8> void radix_sort(T* a, int n) {
    T temp[200200];
    T *dist = temp, *src = a;
    constexpr T mask = (1 << b) - 1;
    constexpr int kn = (bit + b - 1) / b;
    for (int k = 0; k < kn; ++k) {
        T bucket[1 << b] = {};
        T index[1 << b];
        for (int i = 0; i < n; ++i) bucket[mask & (src[i] >> (b*k))] += 1;
        index[0] = 0;
        for (int i = 0; i < (1 << b) - 1; ++i) index[i + 1] = index[i] + bucket[i];
        for (int i = 0; i < n; ++i) dist[index[mask & (src[i] >> (b*k))]++] = src[i];
        swap(dist, src);
    }
    if (kn % 2 == 1) {
        memcpy(a, src, sizeof(T) * n);
    }
}

uint64_t s[200200];
int ind[200200];
int ans[200200];
char *in;

int main() {
    fread(buf, sizeof buf, 1, stdin);

    int n;
    readui(n);
    in = buf;

    rep(i, n) {
        ind[i] = bufi;
        cerr << buf[bufi];
        while(buf[bufi] != '\n') {
            s[i] <<= 6;
            s[i] |= (buf[bufi++] - 'a' + 1);
        }
        bufi++;
    }

    radix_sort<uint64_t, 10, 60>(s, n);

    int c = 0;
    int ai = 0;
    rep(i, n - 1) {
        int j;
        for (j = i + 1; s[i] == s[j]; ++j) {}
        if (j - i == c) {
            ans[ai++] = i;
        } else if (j - i > c) {
            c = j - i;
            ai = 0;
            ans[ai++] = i;
        }
    }
    int outi = 0;

    rep(i, ai) {
        int k = ind[ans[i]];
        while (buf[k] != '\n') {
            out[outi++] = buf[k++];
        }
        out[outi++] = '\n';
    }

    fwrite(out, 1, outi, stdout);

    return 0;
}
