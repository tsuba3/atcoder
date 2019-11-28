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

// Begin Mod
template<typename T, T mod_, bool is_prime = true>
class Mod {
public:
    using Self = Mod<T, mod_, is_prime>;
    T value;
    static constexpr T mod = mod_;
    Mod(T x) { value = x % mod; }
    explicit operator T&() { return value; }
    Self operator +(Self const x) const { return (value + x.value) % mod; }
    Self operator *(Self const x) const { return (value * x.value) % mod; }
    Self operator -(Self const x) const { return (mod + value - x.value) % mod; }
    Self operator /(Self const x) const { return (value * x.inv().value) % mod; }
    Self operator +=(Self const x) { return value = (value + x.value) % mod; }
    Self operator *=(Self const x) { return value = (value * x.value) % mod; }
    Self operator -=(Self const x) { return value = (mod + value - x.value) % mod; }
    Self operator /=(Self const x) { return value = (value * x.inv().value) % mod; }
    Self inv() const {
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
    Self pow(int e) const {
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
// End Mod

// Begin UnionFind
class UnionFind {
public:
    explicit UnionFind(int const size) {
        v.resize(size);
        rep(i, size) v[i] = i;
    }
    vector<int> v;
    bool is_same(int const i, int const j) {
        return root(i) == root(j);
    }
    void unite(int const i, int const j) {
        const int ri = root(i);
        const int rj = root(j);
        if (ri == rj) return;
        v[rj] = ri;
    }
    int root(int const i) {
        if (v[i] == i) return i;
        return v[i] = root(v[i]);
    }
};
// End UnionFind

// End of template.

constexpr char R = 'R';
constexpr char B = 'B';

char inv(char c) {
    return c == R ? B : R;
}

char question(const vector<int>& v) {
    cout << "? ";
    rep(i, v.size() - 1) cout << v[i] << ' ';
    cout << v[v.size() - 1] << '\n' << flush;
    string s;
    cin >> s;
    return s[0];
}

char question(int n, int x) {
    vector<int> v(n);
    rep(i, n) v[i] = x + i;
    return question(v);
}

void answer(const vector<char>& v) {
    cout << "! ";
    for (auto x : v) cout << x;
    cout << flush;
}

int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<char> ans(2 * n, 0);
    vector<int> v(n);

    char first;
    first = question(n, 1);
    debug(first);

    int r = n + 1;
    int l = 1;
    while (r - l > 1) {
        int x = (l + r) / 2;
        char c = question(n, x);
        if (first != c) {
            r = x;
        } else {
            l = x;
        }
    }

    // l is first, l + n is not first, v[l+1 : l+n] は赤青同じ個数
    
    debug(l);
    ans[l] = first;
    ans[l + n] = inv(first);

    for (int i = 1; i < n; ++i) v[i] = l + i;
    for (int i = 0; i < l; ++i) {
        v[0] = i + 1;
        ans[i] = question(v);
    }
    for (int i = l + n; i < 2 * n; ++i) {
        v[0] = i + 1;
        ans[i] = question(v);
    }

    int vi = 1;
    rep(i, 2 * n) {
        if (vi > (n - 1) / 2) break;
        if (ans[i] == R) v[vi++] = i + 1;
    }
    rep(i, 2 * n) {
        if (vi >= n) break;
        if (ans[i] == B) v[vi++] = i + 1;
    }

    rep(i, 2 * n) {
        if (ans[i] == 0) {
            v[0] = i + 1;
            ans[i] = question(v);
        }
    }

    answer(ans);

    return 0;
}

