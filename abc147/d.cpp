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

#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC target ("avx")

#include <chrono>
#include <unistd.h>
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
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <random>

#pragma GCC optimize ("O3")
#pragma GCC target ("avx")

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

// End of template.

char buf[1 << 20], *bp = buf, *bend = buf;
char gc() {
    if (bp == bend) {
        int x = fread(buf, 1, sizeof buf, stdin);
        bend = buf + x;
        bp = buf;
    }
    return *bp++;
}
void readint64(uint64 &n) {
    char c;
    n = 0;
    c = gc();
    for (; '0' <= c && c <= '9'; c = gc())
        n = 10 * n + c - '0';
}

int main(){
    chrono::system_clock::time_point start, end, s1, s2, s3;
    start = chrono::system_clock::now();
    // cin.read(buf, sizeof buf);
    s1 = chrono::system_clock::now();

    constexpr uint64 mod = 1000000007;
    uint64 n;
    readint64(n);
    
    uint64 ones0[16];
    uint64 ones[64] = {};
    // 20 / 16 倍　高速化
    constexpr uint64 mask = (1LL << 0) | (1LL << 16) | (1LL << 32) | (1LL << 48);
    constexpr int n_split = 60000; // nmax = 60000 * 5
    uint64 remain = n;
    rep(i, 5) {
        memset(ones0, 0, sizeof ones0);
        rep(j, n_split / 2) {
            if (remain < 2) break;
            uint64 a0;
            uint64 a1;
            readint64(a0);
            readint64(a1);
            rep(k, 16) {
                ones0[k] += a0 & mask;
                ones0[k] += a1 & mask;
                a0 >>= 1;
                a1 >>= 1;
            }
            remain -= 2;
        }
        constexpr uint64 mask16 = (1LL << 16) - 1;
        rep(j, 4) rep(k, 16) ones[j*16+k] += (ones0[k] >> (16*j)) & mask16;
    }
    if (remain & 1) {
        uint64 a;
        readint64(a);
        rep(k, 64) {
            ones[k] += (a >> k) & 1;
        }
    }

    s2 = chrono::system_clock::now();

    uint64 ans = 0;
    for (uint64 bit = 0; bit < 60; ++bit) {
        ans += ((ones[bit] * (n - ones[bit])) % mod) * ((1LL << bit) % mod);
        ans %= mod;
    }

    print(ans);
    
    end = chrono::system_clock::now();
    
    double t1 = static_cast<double>(chrono::duration_cast<chrono::microseconds>(s1 - start).count() / 1000.0);
    double t2 = static_cast<double>(chrono::duration_cast<chrono::microseconds>(s2 - s1).count() / 1000.0);
    double t3 = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end -s2).count() / 1000.0);
    double t = static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0);
    fprintf(stderr, "%.3fms %.3fms %.3fms %.3fms\n", t1, t2, t3, t);

    return 0;
}


