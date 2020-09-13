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
#include <fstream>

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
const int INF = (1 << 30) - 1;
const int64 INF64 = (1LL << 62) - 1;

template<typename T>
T gcd(T a, T b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
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
template<typename IStream = decltype(cin), typename OStream = decltype(cout)>
struct FastIO {
    char *buf, *OUT, *out;
    OStream &os;

    FastIO(size_t input_size = 1e7, size_t output_size = 1e7) : os(cout) {
        buf = new char[input_size];
        OUT = new char[output_size];
        out = OUT;
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin.read(buf, input_size);
    }

    FastIO(IStream &in, OStream &out, size_t input_size = 1e7, size_t output_size = 1e7) : os(out) {
        buf = new char[input_size];
        OUT = new char[output_size];
        this->out = OUT;
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

    string_view reads() {
        const char *begin = buf;
        char c;
        while (c = readc(), c >= '!') {}
        return string_view(begin, buf - begin - 1);
    }

    string_view readline() {
        const char *begin = buf;
        while (readc() != '\n') {}
        return string_view(begin, buf - begin - 1);
    }

    void writec(const char c) {
        *out++ = c;
    }

    void writes(const string &s) {
        memcpy(out, s.c_str(), s.size());
        out += s.size();
    }

    void writes(const string_view &s) {
        memcpy(out, s.data(), s.size());
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
        if (n == 0) {
            writec('0');
            return;
        }
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
// Begin of sieve
// コンパイル時エラトステネスの篩

constexpr size_t primes_limit[] = {2, 2, 2, 4, 6, 11, 18, 31, 54, 97, 172, 309, 564, 1028, 1900, 3512, 6542, 12251,
                                   23000, 43390, 82025, 155611};

template<size_t N>
struct Sieve {
    uint8_t flag[N / 8 + 2];
    int primes[primes_limit[8 * sizeof(int) - __builtin_clz(N)]]; // N 以下の素数の配列
    int sz; // N 以下の素数の数
    constexpr Sieve() : flag(), primes(), sz(0) {
        rep(i, sizeof flag) flag[i] = 0b10101010;
        flag[0] = 0b10101100;
        for (int i = 3; i <= sqrt(N); i += 2)
            if (flag[i >> 3] >> (i & 7) & 1) {
                for (int p = i * i; p <= N; p += i)
                    flag[p >> 3] &= ~(1 << (p & 7));
            }
        int j = 0;
        rep(i, N + 1) if (flag[i >> 3] >> (i & 7) & 1) primes[j++] = i;
        sz = j;
    }

    template<typename T>
    bool test(T p) const { // p が素数かどうかを返す。p は N 2乗以下であること。
        if (p <= N) return flag[p >> 3] >> (p & 7) & 1;
        for (int i = 0; primes[i] <= sqrt(p) + 1; ++i) {
            if (p % primes[i] == 0) return false;
        }
        return true;
    }
};
// End of sieve


int main() {
    Sieve<1000> sieve;
    FastIO io;
    unordered_set<int> s;
    bool pairwise_coprime = true;

    int n, g = 0;
    io.readui(n);
    vector<int> A(n);
    rep(i, n) io.readui(A[i]), g = gcd(g, A[i]);

    for (int a : A) {
        rep(i, sieve.sz) {
            int p = sieve.primes[i];
            if (a % p == 0) {
                if (s.find(p) != s.end()) pairwise_coprime = false;
                s.insert(p);
            }
            while (a % p == 0) a /= p;
        }
        if (a != 1) {
            if (s.find(a) != s.end()) pairwise_coprime = false;
            s.insert(a);
        }
    }

    if (pairwise_coprime) {
        print("pairwise coprime");
    } else if (g == 1) {
        print("setwise coprime");
    } else {
        print("not coprime");
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
