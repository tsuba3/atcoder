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

    void writes(const string& s) {
        memcpy(out, s.c_str(), s.size());
        out += s.size();
    }

    void writesv(const string_view& s) {
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
        if (n == 0) { writec('0'); return; }
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

template<typename T>
struct Compress {
    vector<T> v;

    constexpr Compress() : v() {}

    constexpr Compress(vector<T> v) : v(v) {
        build();
    }

    static constexpr Compress<T> with_sorted(vector<T> &&v) {
        return Compress<T>{v};
    }

    void build() {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }

    int compress(const T x) const {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    }

    const T &restore(const int i) const { return v[i]; }

    int operator()(const T &&x) const { return compress(x); }

    const T &operator[](const int i) const { return restore(i); }
};


int main() {
    FastIO io;

    int h, w, sh, sw, gh, gw;
    io.readui(h);
    io.readui(w);
    io.readui(sh);
    io.readui(sw);
    io.readui(gh);
    io.readui(gw);
    sh--, sw--, gh--, gw--;

    string_view s[1100];
    rep(i, h) {
        s[i] = string_view(io.buf, w);
        io.buf += w + 1;
    }

    UnionFind uf(h * w);
    for (int wi = 1; wi < w; ++wi) {
        if (s[0][wi] == '.' && s[0][wi - 1] == '.') {
            uf.unite(0 * w + wi - 1, 0 * w + wi);
        }
    }
    for (int hi = 1; hi < h; ++hi) {
        if (s[hi][0] == '.' && s[hi - 1][0] == '.') {
            uf.unite(hi * w + 0, (hi - 1) * w + 0);
        }
        for (int wi = 1; wi < w; ++wi) {
            if (s[hi][wi] == '.') {
                if (s[hi - 1][wi] == '.') {
                    uf.unite(hi * w + wi, (hi - 1) * w + wi);
                }
                if (s[hi][wi - 1] == '.') {
                    uf.unite(hi * w + wi, hi * w + wi - 1);
                }
            }
        }
    }

    rep(i, h * w) uf.root(i);
    Compress<int> c(uf.v);
    vector<int> x(move(uf.v));
    rep(i, h * w) x[i] = c.compress(x[i]);

    vector<vector<int>> vec(c.v.size());
    rep(hi, h) rep(wi, w) {
        set<int> st;
        st.insert(x[hi * w + wi]);
        if (s[hi][wi] == '.') {
            for (int hi2 = max(0, hi - 2); hi2 <= min(h - 1, hi + 2); ++hi2) {
                for (int wi2 = max(0, wi - 2); wi2 <= min(w - 1, wi + 2); ++wi2) {
                    if (s[hi2][wi2] == '.' &&  st.find(x[hi2 * w + wi2]) == st.end()) {
                        vec[x[hi * w + wi]].push_back(x[hi2 * w + wi2]);
                        st.insert(x[hi2 * w + wi2]);
                    }
                }
            }
        }
    }

    /*
    debug("MAP");
    rep(hi, h) {
        rep(wi, w) fprintf(stderr, "%02d ", x[hi * w + wi]);
        cerr << '\n';
    }
     */

    vector<int> dp(h * w, INF);
    dp[x[sh * w + sw]] = 0;
    queue<int> bfs;
    bfs.emplace(x[sh * w + sw]);
    while (!bfs.empty()) {
        const auto i = bfs.front();
        bfs.pop();
        for (const int j : vec[i]) {
            if (dp[j] == INF) {
                dp[j] = dp[i] + 1;
                bfs.push(j);
            }
            if (j == x[gh * w + gw]) goto end_bfs;
        }
    }
    end_bfs:

    if (dp[x[gh * w + gw]] >= INF) {
        io.writes("-1\n");
    } else {
        io.writeui(dp[x[gh * w + gw]]);
        io.writec('\n');
    }

    return 0;
}

/*
     _
  __| |  ___ _ __  _ __
 / _` | / __| '_ \| '_ \
| (_| || (__| |_) | |_) |
 \__,_(_)___| .__/| .__/
            |_|   |_|
*/
