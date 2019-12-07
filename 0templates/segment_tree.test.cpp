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

#include "monoid.cpp"
#include "segment_tree.cpp"

template<typename M>
class TestSegmentTree {
    public:
    using MT = typename M::type;
    TestSegmentTree(int n): seg(n) {
        v.resize(n, M::unit);
    }
    bool get() {
        MT expect = accumulate(v.begin(), v.end(), M::unit, M::f);
        MT actual = seg.get();
        return expect == actual;
    }
    bool get(int i) { return v[i] == seg.get(i); }
    bool get(int l, int r) {
       MT expect = accumulate(v.begin() + l, v.begin() + r, M::unit, M::f);
       MT actual = seg.get(l, r);
       return expect == actual;
    }
    void set(MT x)  { set(0, v.size(), x); seg.set(x); }
    void set(int i, MT x) { v[i] = x; seg.set(i, x); }
    void set(int l, int r, MT x) { for (int i = l; i < r; ++i) v[i] = x; seg.set(l, r, x); }
    template<typename I>
    void set(int l, int r, I const it) {
        I it2 = it;
        for (int i = l; i < r; ++i) v[i] = *it2++;
        seg.set(l, r, it);
    } 
    vector<MT> v;
    SegmentTree<M> seg;
};

template<typename M, typename Op, typename M::type f(typename M::type, typename Op::type, int), bool op_commutative>
class TestLazySegmentTree {
    public:
    using MT = typename M::type;
    using OpT = typename Op::type;
    TestLazySegmentTree(int n): seg(n) {
        v.resize(n, M::unit);
    }
    bool get() {
        MT expect = accumulate(v.begin(), v.end(), M::unit, M::f);
        MT actual = seg.get();
        return expect == actual;
    }
    bool get(int i) { return v[i] == seg.get(i); }
    bool get(int l, int r) {
       MT expect = accumulate(v.begin() + l, v.begin() + r, M::unit, M::f);
       MT actual = seg.get(l, r);
       return expect == actual;
    }
    void set(MT x)  { set(0, v.size(), x); seg.set(x); }
    void set(int i, MT x) { v[i] = x; seg.set(i, x); }
    void set(int l, int r, MT x) { for (int i = l; i < r; ++i) v[i] = x; seg.set(l, r, x); }
    template<typename I>
    void set(int l, int r, I const it) {
        I it2 = it;
        for (int i = l; i < r; ++i) v[i] = *it2++;
        seg.set(l, r, it);
    } 
    void update(OpT op) { rep(i, v.size()) v[i] = f(v[i], op, 1); seg.update(op); }
    void update(int i, OpT op) { v[i] = f(v[i], op, 1); seg.update(i, op); }
    void update(int l, int r, OpT op) { for(int i = l; i < r; ++i) v[i] = f(v[i], op, 1); seg.update(l, r, op); }
    bool eval() {
        seg.eval();
        rep(i, seg.n) if (seg.v[seg.n + i] != v[i]) return false;
        return true;
    }
    vector<MT> v;
    LazySegmentTree<M, Op, f, op_commutative> seg;
};

// End of template.

template<typename T>
T identity(T const& t) { return t; }

int add(int a, int b) { return a + b; }

int minint(int a, int b) { return min(a, b); }

template<>
int Monoid<int, add>::pow(int base, int exp) {
    return base * exp;
}

class Matrix {
    public:
    int a, b, c, d;
    // a b
    // c d
    Matrix operator+(const Matrix& other) const {
        return Matrix{ a + other.a, b + other.b, c + other.c, d + other.d};
    }
    Matrix operator*(const Matrix& other) const {
        return Matrix{
            a * other.a + b * other.c, a * other.b + b * other.d,
            c * other.a + d * other.c, c * other.b + d * other.d,
        };
    }
    Matrix operator*(const int& n) const {
        return Matrix { n * a, n * b, n * c, n * d };
    }
    bool operator==(const Matrix& other) const {
        return a == other.a && b == other.b && c == other.c && d == other.d;
    }
    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }
};

Matrix add(Matrix a, Matrix b) { return a + b; }
Matrix mul(Matrix a, Matrix b) { return a * b; }
int mul(int a, int b) { return a * b; }

template<>
const Matrix Monoid<Matrix, add>::unit(Matrix{0, 0, 0, 0});

template<>
const Matrix Monoid<Matrix, mul>::unit(Matrix{1, 0, 0, 1});

template<>
const int Monoid<int, minint>::unit(INF);

template<>
const int Monoid<int, add>::unit(0);

template<>
const int Monoid<int, mul>::unit(1);

int merge_minint_add(int m, int op, int n) {
    return m + op;
}

int merge_add_add(int m, int op, int n) {
    return m + n * op;
}

Matrix merge_mat_add_mul(const Matrix m, const Matrix op, const int n) {
    return m * op;
}

Matrix merge_mat_mul_int_mul(const Matrix m, const int op, const int n) {
    return m * pow(op, n);
}

mt19937 mt;

int randint(int a, int b) {
    return uniform_int_distribution<int>(a, b - 1)(mt);
}

Matrix randmat() {
    return Matrix {randint(-4, 5), randint(-4, 5), randint(-4, 5), randint(-4, 5)};
}

#define ASSERT(expr) if (!(expr)) { cout << "ERROR " << __LINE__ << '\n'; return false; }

bool test_not_lazy_mat_mul(int n) {
    using M = Monoid<Matrix, mul>;
    TestSegmentTree<M> test(n);
    vector<Matrix> vec(n);
    rep(i, n) vec[i] = randmat();

    rep(i, 10000) {
        int a = randint(0, n);
        int b = randint(a + 1, n + 1);
        int r = randint(0, 3);
        if (r == 0)
            test.set(a, b, randmat());
        else if (r == 1)
            test.set(a, randmat());
        else if (r == 2)
            test.set(a, b, begin(vec) + randint(0, a+1));
        a = randint(0, n);
        b = randint(a + 1, n + 1);
        ASSERT(test.get(a, b));
        if (randint(0, 10) < 1)
            ASSERT(test.get(randint(0, n)));
    }
    ASSERT(test.get());

    return true;
}

bool test_add_min(int n) {
    using M = Monoid<int, minint>;
    using Op = Monoid<int, add>;
    TestLazySegmentTree<M, Op, merge_minint_add, true> test(n);

    test.set(0);
    rep(i, 10000) {
        int a = randint(0, n);
        int b = randint(a + 1, n + 1);
        test.update(a, b, randint(1, 5));
        if (randint(0, 10) < 1) test.update(randint(0, n), randint(1, 5));
        if (randint(0, 10) < 1) test.update(randint(1, 5));
        if (randint(0, 10) <= 8) {
            int a = randint(0, n);
            int b = randint(a + 1, n + 1);
            ASSERT(test.get(a, b));
        }
        if (randint(0, 10) < 1)
            ASSERT(test.get(randint(0, n)));
    }
    ASSERT(test.get());
    ASSERT(test.eval());

    return true;
}

bool test_add_sum(int n) {
    using M = Monoid<int, add>;
    using Op = Monoid<int, add>;
    TestLazySegmentTree<M, Op, merge_add_add, true> test(n);

    rep(i, 10000) {
        int a = randint(0, n);
        int b = randint(a + 1, n + 1);
        int op = randint(1, 5);
        test.update(a, b, op);
        if (randint(0, 10) <= 1) test.update(randint(0, n), randint(1, 5));
        if (randint(0, 10) <= 1) test.update(randint(1, 5));
        if (randint(0, 10) <= 8) {
            int a = randint(0, n);
            int b = randint(a + 1, n + 1);
            ASSERT(test.get(a, b));
        }
        if (randint(0, 10) < 1)
            ASSERT(test.get(randint(0, n)));
    }
    ASSERT(test.get());
    ASSERT(test.eval());

    return true;
}

bool test_add_sum_with_set(int n) {
    using M = Monoid<int, add>;
    using Op = Monoid<int, add>;
    TestLazySegmentTree<M, Op, merge_add_add, true> test(n);
    vector<int> vec(n);
    rep(i, n) vec[i] = i;

    rep(i, 10000) {
        int a = randint(0, n);
        int b = randint(a + 1, n + 1);
        int op = randint(1, 5);
        if (randint(0, 10) < 1) {
            int r = randint(0, 3);
            if (r == 0)
                test.set(a, b, randint(20, 50));
            else if (r == 1)
                test.set(a, randint(20, 50));
            else
                test.set(a, b, begin(vec) + randint(0, a+1));
        } else  {
            test.update(a, b, op);
        }
        if (randint(0, 10) <= 1) test.update(randint(0, n), randint(1, 5));
        if (randint(0, 10) <= 1) test.update(randint(1, 5));
        if (randint(0, 10) <= 8) {
            int a = randint(0, n);
            int b = randint(a + 1, n + 1);
            ASSERT(test.get(a, b));
        }
        if (randint(0, 10) < 1)
            ASSERT(test.get(randint(0, n)));
    }
    ASSERT(test.get());
    ASSERT(test.eval());

    return true;
}

// 更新が非可換
bool test_mat_add_mul(int n) {
    using M = Monoid<Matrix, add>;
    using Op = Monoid<Matrix, mul>;
    TestLazySegmentTree<M, Op, merge_mat_add_mul, false> test(n);
    vector<Matrix> vec(n);
    rep(i, n) vec[i] = randmat();

    rep(i, 10000) {
        int a = randint(0, n);
        int b = randint(a + 1, n + 1);
        Matrix op = randmat();
        if (randint(0, 100) < 1) {
            int r = randint(0, 3);
            if (r == 0)
                test.set(a, b, randmat());
            else if (r == 1)
                test.set(a, randmat());
            else
                test.set(a, b, begin(vec) + randint(0, a+1));
        } else  {
            test.update(a, b, op);
        }
        if (randint(0, 10) <= 1) test.update(randint(0, n), randmat());
        if (randint(0, 10) <= 1) test.update(randmat());
        if (randint(0, 10) <= 8) {
            int a = randint(0, n);
            int b = randint(a + 1, n + 1);
            ASSERT(test.get(a, b));
        }
        if (randint(0, 10) < 1)
            ASSERT(test.get(randint(0, n)));
    }
    ASSERT(test.get());
    ASSERT(test.eval());

    return true;
}

// モノイドが非可換
bool test_mat_mul_int_mul(int n) {
    using M = Monoid<Matrix, mul>;
    using Op = Monoid<int, mul>;
    TestLazySegmentTree<M, Op, merge_mat_mul_int_mul, true> test(n);
    vector<Matrix> vec(n);
    rep(i, n) vec[i] = randmat();

    rep(i, 5000) {
        int a = randint(0, n);
        int b = randint(a + 1, n + 1);
        int op = randint(-2, 3);
        if (randint(0, 100) < 1) {
            int r = randint(0, 3);
            if (r == 0)
                test.set(a, b, randmat());
            else if (r == 1)
                test.set(a, randmat());
            else
                test.set(a, b, begin(vec) + randint(0, a+1));
        } else  {
            test.update(a, b, op);
        }
        if (randint(0, 10) <= 1) test.update(randint(0, n), randint(-2, 3));
        if (randint(0, 10) <= 1) test.update(randint(-2, 3));
        if (randint(0, 10) <= 8) {
            int a = randint(0, n);
            int b = randint(a + 1, n + 1);
            ASSERT(test.get(a, b));
        }
        if (randint(0, 10) < 1)
            ASSERT(test.get(randint(0, n)));
    }
    ASSERT(test.get());
    ASSERT(test.eval());

    return true;
}
// Test: https://abc035.contest.atcoder.jp/tasks/abc035_c
int main(){
    cout << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int TEST_N = 13;
    
    for (int i = 4; i <= TEST_N; ++i) {
        if (test_not_lazy_mat_mul(1 << i))
            cout << "OK  test_not_lazy_mat_mul(" << (1 << i) << ")\n";
        else
            cout << "NG  test_not_lazy_mat_mul(" << (1 << i) << ")\n";
    }
    
    for (int i = 4; i <= TEST_N; ++i) {
        if (test_add_min(1 << i))
            cout << "OK  test_add_min(" << (1 << i) << ")\n";
        else
            cout << "NG  test_add_min(" << (1 << i) << ")\n";
    }
    

    for (int i = 4; i <= TEST_N; ++i) {
        if (test_add_sum(1 << i))
            cout << "OK  test_add_sum(" << (1 << i) << ")\n";
        else
            cout << "NG  test_add_sum(" << (1 << i) << ")\n";
    }

    for (int i = 4; i <= TEST_N; ++i) {
        if (test_add_sum_with_set(1 << i))
            cout << "OK  test_add_sum_with_set(" << (1 << i) << ")\n";
        else
            cout << "NG  test_add_sum_with_set(" << (1 << i) << ")\n";
    }

    for (int i = 4; i <= TEST_N; ++i) {
        if (test_mat_add_mul(1 << i))
            cout << "OK  test_mat_add_mul(" << (1 << i) << ")\n";
        else
            cout << "NG  test_mat_add_mul(" << (1 << i) << ")\n";
    }

    for (int i = 4; i <= TEST_N; ++i) {
        if (test_mat_mul_int_mul(1 << i))
            cout << "OK  test_mat_mul_int_mul(" << (1 << i) << ")\n";
        else
            cout << "NG  test_mat_mul_int_mul(" << (1 << i) << ")\n";
    }

    return 0;
}


