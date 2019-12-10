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

char buf[6000000];
int cnt=0;
void readint64(int64 &n) {
    bool negative = false;
    int c;
    n = 0;
    c = buf[cnt++];
    if (c == '-') negative = true, c = buf[cnt++];
    for (; '0' <= c && c <= '9'; c = buf[cnt++])
        n = 10 * n + c - '0';
    if (negative) n *= -1;
}

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    chrono::system_clock::time_point start, end, s1, s2, s3;
    start = chrono::system_clock::now();
    cin.read(buf, sizeof buf);
    s1 = chrono::system_clock::now();

    constexpr int64 mod = 1000000007;
    int64 n;
    readint64(n);
    
    int64 ones[64];
    memset(ones, 0, sizeof ones);

    int64 a1, a2, a3, a4;
    for (int i = n / 4 + 1; i; --i) {
        int bit = 0;
        readint64(a1);
        readint64(a2);
        readint64(a3);
        readint64(a4);
        while (a1|a2|a3|a4) {
            ones[bit+0] += a1 & 0b0001;
            ones[bit+1] += a1 & 0b0010;
            ones[bit+2] += a1 & 0b0100;
            ones[bit+3] += a1 & 0b1000;
            ones[bit+0] += a2 & 0b0001;
            ones[bit+1] += a2 & 0b0010;
            ones[bit+2] += a2 & 0b0100;
            ones[bit+3] += a2 & 0b1000;
            ones[bit+0] += a3 & 0b0001;
            ones[bit+1] += a3 & 0b0010;
            ones[bit+2] += a3 & 0b0100;
            ones[bit+3] += a3 & 0b1000;
            ones[bit+0] += a4 & 0b0001;
            ones[bit+1] += a4 & 0b0010;
            ones[bit+2] += a4 & 0b0100;
            ones[bit+3] += a4 & 0b1000;
            a1 >>= 4;
            a2 >>= 4;
            a3 >>= 4;
            a4 >>= 4;
            bit += 4;
        }
    }

    ones[ 0] >>= 0;
    ones[ 1] >>= 1;
    ones[ 2] >>= 2;
    ones[ 3] >>= 3;
    ones[ 4] >>= 0;
    ones[ 5] >>= 1;
    ones[ 6] >>= 2;
    ones[ 7] >>= 3;
    ones[ 8] >>= 0;
    ones[ 9] >>= 1;
    ones[10] >>= 2;
    ones[11] >>= 3;
    ones[12] >>= 0;
    ones[13] >>= 1;
    ones[14] >>= 2;
    ones[15] >>= 3;
    ones[16] >>= 0;
    ones[17] >>= 1;
    ones[18] >>= 2;
    ones[19] >>= 3;
    ones[20] >>= 0;
    ones[21] >>= 1;
    ones[22] >>= 2;
    ones[23] >>= 3;
    ones[24] >>= 0;
    ones[25] >>= 1;
    ones[26] >>= 2;
    ones[27] >>= 3;
    ones[28] >>= 0;
    ones[29] >>= 1;
    ones[30] >>= 2;
    ones[31] >>= 3;
    ones[32] >>= 0;
    ones[33] >>= 1;
    ones[34] >>= 2;
    ones[35] >>= 3;
    ones[36] >>= 0;
    ones[37] >>= 1;
    ones[38] >>= 2;
    ones[39] >>= 3;
    ones[40] >>= 0;
    ones[41] >>= 1;
    ones[42] >>= 2;
    ones[43] >>= 3;
    ones[44] >>= 0;
    ones[45] >>= 1;
    ones[46] >>= 2;
    ones[47] >>= 3;
    ones[48] >>= 0;
    ones[49] >>= 1;
    ones[50] >>= 2;
    ones[51] >>= 3;
    ones[52] >>= 0;
    ones[53] >>= 1;
    ones[54] >>= 2;
    ones[55] >>= 3;
    ones[56] >>= 0;
    ones[57] >>= 1;
    ones[58] >>= 2;
    ones[59] >>= 3;
    ones[60] >>= 0;
    ones[61] >>= 1;
    ones[62] >>= 2;
    ones[63] >>= 3;


    s2 = chrono::system_clock::now();
    int64 ans = 0;
    for(int64 bit = 0; bit < 64; ++bit) {
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

