// Begin of sieve
// コンパイル時エラトステネスの篩

constexpr size_t primes_limit[] = {2,2,2,4,6,11,18,31,54,97,172,309,564,1028,1900,3512,6542,12251,23000,43390,82025,155611};

template<size_t N>
struct Sieve {
    uint8_t flag[N / 8 + 2];
    int primes[primes_limit[8*sizeof(int) - __builtin_clz(N)]]; // N 以下の素数の配列
    int sz; // N 以下の素数の数
    constexpr Sieve() : flag(), primes(), sz(0) {
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
// End of sieve
