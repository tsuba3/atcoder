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

int main() {
    auto st = chrono::high_resolution_clock::now();
    const Sieve sieve(int(1e8));
    auto et = chrono::high_resolution_clock::now();
    cout << "Erathostenes " << chrono::duration_cast<chrono::milliseconds>(et - st).count() << "ms" << endl;
/*
    auto st2 = chrono::high_resolution_clock::now();
    const AtkinSieve atkin(int(1e8));
    auto et2 = chrono::high_resolution_clock::now();
    cout << "Atkin        " << chrono::duration_cast<chrono::milliseconds>(et2 - st2).count() << "ms" << endl;
    */
    for (int p : {2, 3, 5, 7, 3209, 2857}) check(sieve.is_prime(p), true);
    for (int np : {16, 13 * 17, 283 * 371, 3 * 283}) check(sieve.is_prime(np), false);
    /*
    for (int i = 1; i <= 1e8; i += 1) {
        if (sieve.is_prime(i) != atkin.is_prime(i)) {
            cout << "❌ " << i << endl;
            return 1;
        }
    }
    */

    return flag;
}
