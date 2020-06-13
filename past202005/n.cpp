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
        if (n >= 1e4) {
            size = n >= 1e5 ? 6 : 5;
        } else if (n >= 1e2) {
            size = n >= 1e3 ? 4 : 3;
        } else {
            size = n >= 1e1 ? 2 : 1;
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
    int get_ad_hoc(int l, int r, int *a) {
        // M must be commutative.
        int an = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) *a++ = l++, ++an;
            if (r & 1) *a++ = --r, ++an;
        }
        return an;
    }
    void build(int l, int r) {
        _build(l + n, r + n);
    }
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

int _max(const int lhs, const int rhs) { return max(lhs, rhs); }
template<> const int Monoid<int, _max>::unit(-1);

struct MinatoAqua {
    int x[200200];
    const int n;
    SegmentTree<Monoid<int, _max>> seg;

    MinatoAqua(int n): n(n), seg(n) {
        rep(i, n) x[i] = i + 1;
    }
    void sort(int l, int r) {
        r--;
        int a[100];
        int an = seg.get_ad_hoc(l, r, a);
        while (true) {
            int i = -1;
            rep(ai, an) chmax(i, seg.v[a[ai]]);
            if (i == -1) break;
            swap(i);
        }
    }
    void swap(int i) {
        /*
        int a = i - 1, b = i, c = i + 1, d = i + 2, B = c, C = b;
        if (a >= 0) {
            if (x[a] > x[b]) {if (x[a] < x[B]) s.erase(a);}
            else if (x[a] > x[B]) s.insert(a);
        }
        if (x[b] > x[c]) {if (x[B] < x[C]) s.erase(b);}
        else {if (x[B] > x[C]) s.insert(b);}
        if (d < n) {
            if (x[c] > x[d]) {if(x[C] < x[d]) s.erase(c);}
            else {if (x[C] > x[d]) s.insert(c);}
        }
         */
        std::swap(x[i], x[i + 1]);
        if (x[i] < x[i + 1]) seg.bulk_set(i, -1); else seg.bulk_set(i, i);
        if (i > 0) {
            if (x[i - 1] < x[i]) seg.bulk_set(i - 1, -1); else seg.bulk_set(i - 1, i - 1);
        }
        if (i + 2 < n) {
            if (x[i + 1] < x[i + 2]) seg.bulk_set(i + 1, -1); else seg.bulk_set(i + 1, i + 1);
        }
        seg.build(max(0, i - 1),  i + 2);
    }
};

int main() {
    FastIO io;
    int n, q;
    io.readui(n), io.readui(q);
    MinatoAqua aqua(n);
    rep(qi, q) {
        char t = io.readc();
        int x, y;
        io.readc();
        if (t == '1') {
            io.readui(x);
            io.buf += 2;
            x--;
            aqua.swap(x);
        } else {
            io.readui(x), io.readui(y);
            x--;
            aqua.sort(x, y);
        }
    }

    rep(i, n - 1) io.writeui(aqua.x[i]), io.writec(' ');
    io.writeui(aqua.x[n - 1]), io.writec('\n');

    return 0;
}

