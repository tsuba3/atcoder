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
template <typename IStream = decltype(cin), typename OStream = decltype(cout)>
struct FastIO {
    char *buf, *OUT, *out;
    OStream& os;

    FastIO(size_t input_size = 1e7, size_t output_size = 1e7): os(cout) {
        buf = new char[input_size];
        OUT = new char[output_size];
        out = OUT;
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin.read(buf, input_size);
    }

    FastIO(IStream& in, OStream& out, size_t input_size = 1e7, size_t output_size = 1e7): os(out) {
        buf = new char[input_size];
        OUT = new char[output_size];
        this-> out = OUT;
        in.read(buf, input_size);
    }

    ~FastIO() {
        os.write(OUT, out - OUT);
    }

    char readc() {
        return *buf++;
    }

    template<typename T>
    void readui(T &n) {
        n = 0;
        char c = readc();
        for (; '0' <= c && c <= '9'; c = readc())
            n = 10 * n + c - '0';
    }

    template<typename T>
    void readi(T &n) {
        bool negative = false;
        if (*buf == '-') negative = true, buf++;
        readui(n);
        if (negative) n = -n;
    }

    template<typename T>
    void readuf(T &x) {
        x = 0;
        T y = 0;
        int z = 0;
        char c = readc();
        for (; '0' <= c && c <= '9'; c = readc())
            x = 10 * x + c - '0';
        if (buf[-1] == '.')
            for (; '0' <= c && c <= '9'; c = readc(), ++z)
                y = 10 * y + c - '0';
        x += y / pow(10, z);
    }

    template<typename T>
    void readf(T &x) {
        bool negative = false;
        if (*buf == '-') negative = true, buf++;
        readuf(x);
        if (negative) x = -x;
    }

    void reads(string &s) {
        const char *begin = buf;
        char c;
        while (c = readc(), c != ' ' && c != '\n') {}
        s = string(begin, buf);
    }

    void readline(string &s) {
        const char *begin = buf;
        while (readc() != '\n') {}
        s = string(begin, buf);
    }

    void writec(char c) {
        *out++ = c;
    }

    void writes(string& s) {
        memcpy(out, s.c_str(), s.size());
        out += s.size();
    }

    constexpr static char digit_pairs[] = {
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
        // if (n == 0) writec('0');
        int size;
        if (n >= 1e9) {
            if (n >= 1e10) size = 11; else size = 10;
        } else if (n >= 1e5) {
            if (n >= 1e7) {
                if (n >= 1e8) size = 9; else size = 8;
            } else {
                if (n >= 1e6) size = 7; else size = 6;
            }
        } else {
            if (n >= 1e3) {
                if (n >= 1e4) size = 5; else size = 4;
            } else if (n >= 1e1) {
                if (n >= 1e2) size = 3; else size = 2;
            } else {
                size = 1;
            }
        }
        char *c = out + size;
        out += size;
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

    int n, q, cnt[100100] = {};
    int64 x = 0;
    io.readui(n);
    rep(i, n) {
        int a;
        io.readui(a);
        x += a;
        cnt[a] += 1;
    }
    io.readui(q);
    rep(i, q) {
        int b, c;
        io.readui(b), io.readui(c);
        x -= cnt[b] * (int64) b;
        x += cnt[b] * (int64) c;
        cnt[c] += cnt[b];
        cnt[b] = 0;
        io.writeui(x);
        io.writec('\n');
    }


    return 0;
}

