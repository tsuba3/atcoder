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
// Begin of sieve
// コンパイル時エラトステネスの篩

constexpr size_t primes_limit[] = {2,2,2,4,6,11,18,31,54,97,172,309,564,1028,1900,3512,6542,12251,23000,43390,82025,155611};

template<size_t N>
struct Sieve {
    uint8_t flag[N / 8 + 2];
    int primes[primes_limit[8*sizeof(int) - __builtin_clz(N)]]; // N 以下の素数の配列
    int sz; // N 以下の素数の数
     Sieve() : flag(), primes(), sz(0) {
        rep(i, sizeof flag) flag[i] = 0b10101010;
        flag[0] = 0b10101100;
        for (int i = 3; i <= sqrt(N); i += 2) if (flag[i>>3] >> (i&7) & 1) {
                for (int p = i * i; p <= N; p += i)
                    flag[p >> 3] &= ~(1 << (p&7));
            }
        int j = 0;
        rep(i, N + 1) if (flag[i >> 3] >> (i & 7) & 1) primes[j++] = i;
        sz = j;
    }
    template<typename T> bool test(T p) const { // p が素数かどうかを返す。p は N 2乗以下であること。
        if (p <= N) return flag[p >> 3] >> (p & 7) & 1;
        for (int i = 0; primes[i] <= sqrt(p) + 1; ++i) {
            if (p % primes[i] == 0) return false;
        }
        return true;
    }
};
// End of sieve

int main() {
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    const Sieve<1010> s;

    int n;
    cin >> n;

    int ans = 0;
    for (int abx = 1; abx <= n - 1; ++abx) {
        int ab = abx;
        int cnt = 1;
        rep(si, s.sz) {
            int c = 0;
            while (ab % s.primes[si] == 0) {
                ab /= s.primes[si];
                c += 1;
            }
            cnt *= c + 1;
        }
        if (ab != 1) cnt *= 2;
        ans += cnt;
    }

    print(ans);


    return 0;
}

/*
  ___   ___ _ __  _ __
 / __| / __| '_ \| '_ \
| (__ | (__| |_) | |_) |
 \___(_)___| .__/| .__/
           |_|   |_|
*/
