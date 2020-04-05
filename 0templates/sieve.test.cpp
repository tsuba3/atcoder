#include <bits/stdc++.h>

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

#include "sieve.cpp"

int flag = 0;

template<typename T>
void check(T a, T b) {
    if (a != b) {
        flag = 1;
        cout << "❌ expected: " << a << " actual: " << b << endl;
    } else {
        cout << "✅ expected: " << a << " actual: " << b << endl;
    }
}

constexpr Sieve<100> s100;
constexpr Sieve<2000> s2000;
constexpr Sieve<10000> s10000;
constexpr Sieve<100000> s100000;

int main() {

    check(25, s100.sz);
    check(303, s2000.sz);
    check(1229, s10000.sz);
    check(9592, s100000.sz);
    check(71, s100.primes[19]);
    check(71, s100000.primes[19]);
    check(7919, s100000.primes[999]);
    check(true, s100000.test(283));
    check(false, s100000.test(4945));
    check(false, s100000.test(123456789LL));
    check(true, s100000.test(1000000009));

    return flag;
}
