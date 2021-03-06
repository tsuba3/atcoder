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
template<typename I> void dbg(I bgn, I end) {
    for (int i = 0; bgn < end; ++bgn, ++i) cerr << i << " : " << *bgn << '\n';
}
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
struct FastIO {
    char *buf, *OUT;
    int bufi = 0, outi = 0;

    FastIO() {
        buf = new char[10000000];
        OUT = new char[10000000];
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin.read(buf, 10000000);
    }

    ~FastIO() {
        cout.write(OUT, outi);
    }

    char readc() {
        return buf[bufi++];
    }

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

    void writec(char c) {
        OUT[outi++] = c;
    }

    void writes(string& s) {
        memcpy(OUT + outi, s.c_str(), s.size());
        outi += s.size();
    }

    static constexpr char digit_pairs[] = {
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

    template<typename T>
    void writei(T n) {
        if (n < 0) {
            writec('-');
            writeui(-n);
        } else {
            writeui(n);
        }
    }
};
// end fast io


int main() {
    FastIO io;
    int n, l, t_run, t_jumpe, t_h, dp[100100];
    bool x[100100] = {};
    io.readui(n), io.readui(l);
    rep(i, n) {
        int xx;
        io.readui(xx);
        x[xx] = true;
    }
    io.readui(t_run), io.readui(t_jumpe), io.readui(t_h);

    fill(begin(dp), begin(dp) + l + 1, INF);
    dp[0] = 0;
    rep(i, l) {
        int t1, t2, t3;
        t1 = dp[i];
        if (x[i]) t1 += t_h;
        t1 += t_run;
        t2 = t1 + t_jumpe;
        t3 = t2 + 2 * t_jumpe;
        chmin(dp[i + 1], t1);
        chmin(dp[i + 2], t2);
        chmin(dp[i + 4], t3);
    }

    int ans = dp[l];
    chmin (ans, dp[l - 1] + t_run + (x[l - 1] ? t_h : 0));
    if (l - 1 >= 0) chmin(ans, dp[l - 1] + (x[l - 1] ? t_h : 0) + t_run / 2 + t_jumpe / 2);
    if (l - 2 >= 0) chmin(ans, dp[l - 2] + (x[l - 2] ? t_h : 0) + t_run / 2 + t_jumpe / 2 + t_jumpe);
    if (l - 3 >= 0) chmin(ans, dp[l - 3] + (x[l - 3] ? t_h : 0) + t_run / 2 + t_jumpe / 2 + 2 * t_jumpe);
    io.writeui(ans);
    io.writec('\n');

    return 0;
}

