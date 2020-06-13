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
        if (n == 0) writec('0');
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
// begin of list
/*
 * Array of linked list. N is max size of array. M is max total size of linked list.
 * An instance must be global variable to zero fill arrays.
 * Equivalent to vector<T>
*/
template<typename T, int N, int M>
class List {
    int k = 0;
public:
    int head[N];
    pair<int, T> nodes[M];
    class ListNode {
        List<T, N, M>& list;
        int i;
        int pointer;
    public:
        ListNode(List<T, N, M>& list, int i, int pointer = -1): list(list) {
            this->i = i, this->pointer = pointer;
        }
        void push_back(T x) {
            list.nodes[++list.k] = make_pair(list.head[i], x);
            list.head[i] = list.k;
        }
        void emplace_back(T&& x) {
            list.nodes[++list.k] = make_pair(list.head[i], x);
            list.head[i] = list.k;
        }
        T& operator *() { return list.nodes[pointer].second; }
        bool operator ==(ListNode& other) { return pointer == other.pointer; }
        bool operator !=(ListNode& other) { return pointer != other.pointer; }
        void operator ++() { pointer = list.nodes[pointer].first; }
        ListNode begin() {
            return ListNode(list, i, list.head[i]);
        }
        ListNode end() {
            return ListNode(list, i, 0);
        }
    };
    ListNode operator[](int i) {
        return ListNode(*this, i, head[i]);
    }
};
// end of list

List<int, 100100, 200200> vec;
int dp[17][140000];

struct {
    int l = 0;
    int r = 0;
    int que[100100];
    void push(int x) {que[r++] = x;}
    int front() { return que[l]; }
    void pop() { l++; }
    void reset() { l = r = 0; }
    bool empty() { return l == r; }
} que;

int main() {
    FastIO io;

    int n, m, s, tn, t[17], d[17][17];
    io.readui(n), io.readui(m);
    rep(i, m) {
        int u, v;
        io.readui(u), io.readui(v);
        u--, v--;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    io.readui(s);
    s--;
    io.readui(tn);
    rep(i, tn) io.readui(t[i]), t[i]--;
    t[tn] = s;

    rep(ti, tn + 1) {
        int bfs[100100];
        fill(begin(bfs), begin(bfs) + n, INF);
        que.reset();
        bfs[t[ti]] = 0;
        que.push(t[ti]);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v : vec[u]) {
                if (chmin(bfs[v], bfs[u] + 1)) {
                    que.push(v);
                }
            }
        }
        rep(tj, tn + 1) {
            d[ti][tj] = bfs[t[tj]];
        }
    }

    fill(dp[0], dp[17], INF);
    dp[tn][1 << tn] = 0;
    for (unsigned int bit = 1 << tn; bit < 1 << (tn + 1); ++bit) {
        rep(ti, tn + 1) if (bit >> ti & 1) {
            rep(tj, tn + 1) {
                chmin(dp[tj][bit | (1 << tj)], dp[ti][bit] + d[ti][tj]);
            }
        }
    }

    int ans = INF;
    rep(ti, tn + 1) chmin(ans, dp[ti][(2 << tn) - 1]);
    io.writeui(ans);
    io.writec('\n');

    return 0;
}

