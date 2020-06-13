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
    char *buf, *OUT;
    int bufi = 0, outi = 0;
    OStream& out;

    FastIO(size_t input_size = 1e7, size_t output_size = 1e7): out(cout) {
        buf = new char[input_size];
        OUT = new char[output_size];
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin.read(buf, input_size);
    }

    FastIO(IStream& in, OStream& out, size_t input_size = 1e7, size_t output_size = 1e7): out(out) {
        buf = new char[input_size];
        OUT = new char[output_size];
        in.read(buf, input_size);
    }

    ~FastIO() {
        out.write(OUT, outi);
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
        // n is within [1, 1e9]
        int size;
        if (n >= 1e8) {
            size = n >= 1e9 ? 10 : 9;
        } else if (n >= 1e4) {
            if (n >= 1e6) {
                size = n >= 1e7 ? 8 : 7;
            } else {
                size = n >= 1e5 ? 6 : 5;
            }
        } else {
            if (n >= 1e2) {
                size = n >= 1e3 ? 4 : 3;
            } else {
                size = n >= 1e1 ? 2 : 1;
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
// begin monoid
template<typename T, T f_(T const, T const)>
class Monoid {
public:
    using type = T;

    static T f(T const a, T const b) {
        return f_(a, b);
    }

    static const T unit;

    template<typename I>
    static T concat(I const& begin, I const& end) {
        return accumulate(begin, end, unit, f);
    }

    static T pow(T base, int exp) {
        T res = unit;
        while (exp > 0) {
            if (exp & 1) res = f(base, res);
            base = f(base, base);
            exp >>= 1;
        }
        return res;
    }
};
// end monoid
// begin segment_tree
// monoid に依存
template<typename M>
typename M::type st_default(typename M::type const m, typename M::type const op, int const b) {
    return M::f(m, op);
}

/*
 * セグメントツリー
 */
template<typename M>
class SegmentTree {
public:
    using MT = typename M::type;
    SegmentTree(const int n) {
        depth = int (ceil(log2(max(2, n))));
        this->n = 1 << depth;
        v.resize(2 * this->n, M::unit);
    }
    void bulk_set(int i, MT const m) {
        v[n + i] = m;
    }
    void set(int i, MT const m) {
        i += n;
        v[i] = m;
        _build(i, i + 1);
    }
    void set(int l, int r, MT const m) {
        l += n; r += n;
        for (int i = l; i < r; ++i) v[i] = m;
        _build(l, r);
    }
    template<typename I>
    void set(int l, int r, I it) {
        l += n; r += n;
        for (int i = l; i < r; ++i) v[i] = *it++;
        _build(l, r);
    }
    MT get() const {
        return v[1];
    }
    MT get(int const i) {
        return v[n + i];
    }
    MT get(int l, int r) {
        MT L = M::unit, R = M::unit;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = M::f(L, v[l++]);
            if (r & 1) R = M::f(v[--r], R);
        }
        return M::f(L, R);
    }

    void build(int l, int r) {_build(l + n, r + n);}
    void _build(int l, int r) {
        r--;
        l >>= 1; r >>= 1;
        while (l > 0) {
            for (int i = l; i <= r; ++i) v[i] = M::f(v[2 * i], v[2 * i + 1]);
            l >>= 1; r >>= 1;
        }
    }

    vector<MT> v;
    int n;
    int depth;
};


// end segment_tree

struct Indexed {
    int v;
    int idx;
};

Indexed f(Indexed lhs, Indexed rhs) {
    return lhs.v < rhs.v ? rhs : lhs;
}

using M = Monoid<Indexed, f>;
template<> const Indexed M::unit({0, -1});

using Seg = SegmentTree<M>;

int main() {
    // fstream in("l.in");
    // fstream out("l.out");
    // FastIO io(in, out);
    FastIO io;
    int n, m, ti = 0;
    // int k[100100], t[500500];
    vector<int> k(100100), t(500500);
    io.readui(n);
    Seg seg1(n), seg2(n);
    rep(i, n) {
        int K;
        io.readui(K);
        k[i] = ti;
        rep(j, K) {
            io.readui(t[ti++]);
        }
        t[ti++] = 0;
        t[ti++] = 0;
        seg1.bulk_set(i, {t[k[i]++], i});
        seg2.bulk_set(i, {t[k[i]++], i});
    }
    seg1.build(0, n);
    seg2.build(0, n);

    io.readui(m);
    rep(mi, m) {
        int a;
        io.readui(a);
        if (a == 2) {
            const auto x1 = seg1.get(), x2 = seg2.get();
            if (x1.v < x2.v) {
                io.writeui(x2.v);
                io.writec('\n');
                seg2.set(x2.idx, {t[k[x2.idx]++], x2.idx});
            } else {
                io.writeui(x1.v);
                io.writec('\n');
                seg1.set(x1.idx, seg2.get(x1.idx));
                seg2.set(x1.idx, {t[k[x1.idx]++], x1.idx});
            }
        } else {
            const auto x = seg1.get();
            io.writeui(x.v);
            io.writec('\n');
            seg1.set(x.idx, seg2.get(x.idx));
            seg2.set(x.idx, {t[k[x.idx]++], x.idx});
        }
    }

    return 0;
}

