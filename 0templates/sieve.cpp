// Begin of sieve
// コンパイル時エラトステネスの篩

constexpr size_t primes_limit[] = {2,2,2,4,6,11,18,31,54,97,172,309,564,1028,1900,3512,6542,12251,23000,43390,82025,155611};

template<size_t N>
struct CompileTimeSieve {
    uint8_t flag[N / 8 + 2];
    int primes[primes_limit[8*sizeof(int) - __builtin_clz(N)]]; // N 以下の素数の配列
    int sz; // N 以下の素数の数
    constexpr CompileTimeSieve() : flag(), primes(), sz(0) {
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

template<typename T=int>
struct Sieve {
    vector<bool> flag;
    Sieve(const T n) : flag(n + 1, true) { // n 以下の素数を列挙
        flag[0] = flag[1] = false;
        for (T i = 4; i < n; i += 2) flag[i] = false;
        for (T i = 3; i <= sqrt(n); i += 2) if (flag[i]) {
            for (T p = i * i; p <= n; p += i) flag[p] = false;
        }
    }
    bool is_prime(T n) const {
        return flag[n];
    }
    vector<T> list() const {
        vector<T> v;
        v.push_back(2);
        for (T i = 3; i < flag.size(); i += 2) if (flag[i]) v.push_back(i);
        return v;
    }
};
/*
// n 以下の素数を O(n) で篩う
template<typename T=int>
struct AtkinSieve {
    vector<bool> flag;
    AtkinSieve(const T limit) : flag(limit + 100, true) {
        const T s[] = {1,7,11,13,17,19,23,29,31,37,41,43,47,49,53,59};
        uint64 C1 = 0b100010000000100010000000100000000000100010000000000010; // {1,13,17,29,37,41,49,53}
        uint64 C2 = 0b10000000000010000000000010000000000010000000; // {7,19,31,43}
        uint64 C3 = 0b100000000000100000000000000000000000100000000000100000000000; // {11,23,47,59}
        for (T w = 0; w <= limit / 60; ++w) for (T x : s) flag[60 * w + x] = false;
        for (T x = 1, n = 0; 4 * x * x <= limit; ++x)
            for (T y = 1; (n = 4 * x * x + y * y) <= limit; y += 2)
                if ((1 << (n % 60)) & C1)
                    flag[n] = !flag[n];
        for (T x = 1, n = 0; 3 * x * x <= limit; x += 2)
            for (T y = 2; (n = 3 * x * x + y * y) <= limit; y += 2)
                if ((1 << (n % 60)) & C2)
                    flag[n] = !flag[n];
        for (T x = 2, n = 0; 2 * x * x - 1 <= limit; x += 1)
            for (T y = x - 1; y > 0; y -= 2)
                if ((1 << (n % 60)) & C3)
                    flag[n] = !flag[n];

        flag[1] = false;
        for (T w = 0; w <= limit / 60; ++w)
            for (T x : s) {
                T n;
                if (flag[n = 60 * w + x])
                    for (T a = 0; a <= limit / n / n / 60; a += 1)
                        for (T b : s)
                            flag[60 * a + b] = false;
            }

        for (T x : {2, 3, 5}) flag[x] = true;
        for (T x : {0, 1, 4, 6}) flag[x] = false;
    }
    bool is_prime(T n) const {
        return flag[n];
    }
};
*/

// End of sieve
