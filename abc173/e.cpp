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
        if (is_prime) return pow(mod - 2);
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

constexpr int64 mod = 1e9 + 7;
using M = Mod<int64, mod>;


int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    bool zero = false;
    vector<int64> p, m;
    cin >> n >> k;
    rep(i, n) {
        int a;
        cin >> a;
        if (a > 0) p.push_back(a);
        if (a < 0) m.push_back(-a);
        if (a == 0) zero = true;
    }

    M ans = 1;

    if (n == k) {
        for (auto x : p) ans *= x;
        for (auto x : m) ans *= M(-x);
        if (zero) ans = 0;
        debug(__LINE__);
        print(ans);
        return 0;
    } else if (p.size() + m.size() < k) {
        debug(__LINE__);
        print(0);
        return 0;
    } else if (p.size() + m.size() == k && p.size() % 2 == 1 && zero) {
        debug(__LINE__);
        print(0);
        return 0;
    }

    sort(p.begin(), p.end());
    sort(m.begin(), m.end());

    if (k & 1) {
        if (p.size() >= 1) {
            ans *= p.back();
            p.pop_back();
            k -= 1;
        } else { // p.size() == 0)
            if (zero) {
                debug(__LINE__);
                print(0);
                return 0;
            } else {
                rep(i, k) ans *= m[i];
                debug(__LINE__);
                print(ans * M(-1));
                return 0;
            }
        }
    }


    rep(i, k / 2) {
        if (p.size() >= 2 && m.size() >= 2) {
            if (p.back() * *(p.end() - 2) > m.back() * *(m.end() - 2)) {
                ans *= p.back();
                ans *= *(p.end() - 2);
                p.pop_back();
                p.pop_back();
            } else {
                ans *= m.back();
                ans *= *(m.end() - 2);
                m.pop_back();
                m.pop_back();
            }
        } else if (p.size() >= 2) {
            ans *= p.back();
            ans *= *(p.end() - 2);
            p.pop_back();
            p.pop_back();
        } else if (m.size() >= 2) {
            ans *= m.back();
            ans *= *(m.end() - 2);
            m.pop_back();
            m.pop_back();
        } else {
            debug(__LINE__);
            return 13;
        }
    }

    debug(__LINE__);
    print(ans);

    return 0;
}

/*
  ___   ___ _ __  _ __
 / _ \ / __| '_ \| '_ \
|  __/| (__| |_) | |_) |
 \___(_)___| .__/| .__/
           |_|   |_|
*/
