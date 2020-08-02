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

    FastIO(size_t input_size = 2e7, size_t output_size = 2e7): os(cout) {
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
        while (c = readc(), c != ' ' && c != '\n') {}
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

    void writes(const string_view& s) {
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
        if (n >= 1e4) {
            if (n >= 1e5) size = 6; else size = 5;
        } else if (n >= 1e2) {
            if (n >= 1e3) size = 4; else size = 3;
        } else {
            if (n >= 1e1) size = 2; else size = 1;
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
        v.resize(2 * this->n);
        // ad hoc: 全要素を1で初期化
        int s = 1;
        int x = v.size() / 2;
        while (x > 0) {
            fill(v.begin() + s, v.begin() + s + s, x);
            s *= 2;
            x /= 2;
        }
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

template< typename T, int b = 8, int bit = sizeof(T) * 8> void radix_sort(T* a, int n) {
    vector<T> temp(n);
    T *dist = temp.data(), *src = a;
    constexpr int mask = (1 << b) - 1;
    constexpr int kn = (bit + b - 1) / b;
    for (int k = 0; k < kn; ++k) {
        int bucket[1 << b] = {};
        int index[1 << b];
        for (int i = 0; i < n; ++i) bucket[mask & (src[i].r >> (b*k))] += 1;
        index[0] = 0;
        for (int i = 0; i < (1 << b) - 1; ++i) index[i + 1] = index[i] + bucket[i];
        for (int i = 0; i < n; ++i) dist[index[mask & (src[i].r >> (b*k))]++] = src[i];
        swap(dist, src);
    }
    if (kn % 2 == 1) {
        memcpy(a, src, sizeof(T) * n);
    }
}


int intadd(int lhs, int rhs) { return lhs + rhs; }
using M = Monoid<int, intadd>;
template<> const int M::unit(0);
using Seg = SegmentTree<M>;


struct Q {
    int l;
    int r;
    int i;
};

int main() {
    FastIO io;

    int n, qn;
    io.readui(n), io.readui(qn);
    vector<int> c(n);
    vector<Q> q(qn);
    vector<int> ans(qn);
    vector<int> last(n, -1);
    rep(i, n) io.readui(c[i]), c[i]--;
    rep(i, qn) q[i].i = i, io.readui(q[i].l), io.readui(q[i].r), q[i].l--;

    radix_sort<Q, 10, 20>(q.data(), qn);

    Seg seg(n); // ad hoc: 全要素を1で初期化

    int R = 0;
    for (const Q x : q) {
        for (; R < x.r; ++R) {
            if (last[c[R]] != -1) seg.set(last[c[R]], 0);
            last[c[R]] = R;
            // seg.set(R, 1);
        }
        ans[x.i] = seg.get(x.l, x.r);
    }

    for (const auto x : ans) io.writeui(x), io.writec('\n');

    return 0;
}

/*
  __
 / _| ___ _ __  _ __
| |_ / __| '_ \| '_ \
|  _| (__| |_) | |_) |
|_|(_)___| .__/| .__/
         |_|   |_|
*/
