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

#include <boost/rational.hpp>

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

// Begin Mod
template<typename T, T mod_, bool is_prime = true>
class Mod {
public:
    using Self = Mod<T, mod_, is_prime>;
    T value;
    static constexpr T mod = mod_;
    constexpr Mod() : value() {}
    constexpr Mod(T x) : value() { value = (x + mod) % mod; }
    explicit constexpr operator T&() { return value; }
    constexpr Self operator +(Self const x) const { return (value + x.value) % mod; }
    constexpr Self operator *(Self const x) const { return (value * x.value) % mod; }
    constexpr Self operator -(Self const x) const { return (mod + value - x.value) % mod; }
    constexpr Self operator /(Self const x) const { return (value * x.inv().value) % mod; }
    constexpr Self operator +=(Self const x) { return value = (value + x.value) % mod; }
    constexpr Self operator *=(Self const x) { return value = (value * x.value) % mod; }
    constexpr Self operator -=(Self const x) { return value = (mod + value - x.value) % mod; }
    constexpr Self operator /=(Self const x) { return value = (value * x.inv().value) % mod; }
    constexpr Self inv() const {
        T a = value, b = mod, u = 1, v = 0;
        while (b) {
            T t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= mod;
        if (u < 0) u += mod;
        return u;
    }
    constexpr Self pow(int e) const {
        if (e < 0) return inv().pow(-e);
        if (is_prime) e %= mod - 1;
        Self base = value;
        Self res = 1;
        while (e > 0) {
            if (e & 1) res *= base;
            base *= base;
            e >>= 1;
        }
        return res;
    }
};

template<typename T, T mod>
istream& operator>>(istream& stream, Mod<T, mod>& m) {
    return stream >> m.value;
}

template<typename T, T mod>
ostream& operator<<(ostream& stream, const Mod<T, mod>& m) {
    return stream << m.value;
}
// End Mod
// begin fast io

char buf[10000000], OUT[10000000];
int bufi = 0, outi = 0;

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

template<typename T>
void writei(T n) {
    if (n < 0) {
        writec('-');
        writeui(-n);
    } else {
        writeui(n);
    }
}

// end fast io

constexpr int64 mod = 1e9 + 7;
using M = Mod<int64, mod>;
using R = boost::rational<int64>;

struct P2 {
    int64 a[200200];
    constexpr P2(): a() {
        a[0] = 1;
        for (int i = 0; i < 200199; ++i) a[i + 1] = (a[i] * 2) % mod;
    }
    M operator[](int i) const { return M(a[i]); }
};
constexpr P2 p2;

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.read(buf, sizeof buf);

    M ans(0);
    map<R, int> m;
    int zz = 0; // (0, 0)
    int zero = 0;
    int inf = 0;
    int n;
    readui(n);
    rep(i, n) {
        int64 a, b;
        readi(a), readi(b);
        if (a == 0) {
            if (b == 0) {
                zz += 1;
            } else  {
                zero += 1;
            }
        } else {
            if (b == 0) {
                inf += 1;
            } else {
                R I(a, b);
                m[I] += 1;
            }
        }
    }

    ans = p2[zero] + p2[inf] - 1;
    auto e = m.end();
    for (auto it = m.begin(); it != e; ++it) {
        ans *= p2[it->second] + p2[m[-1 / it->first]] - 1;
        it -> second = 0;
        m[-1 / it->first] = 0;
    }

    ans += M(zz - 1);
    print(ans.value);

    return 0;
}

