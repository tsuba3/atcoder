from functools import reduce

mod = 10 ** 9 + 7
def madd(x, y):
    ret = x + y
    return ret if ret < mod else ret - mod
def msub(x, y):
    ret = mod + x - y
    return ret if ret < mod else ret - mod
def mmul(x, y):
    return (x * y) % mod
def mpow(x, n):
    ret = 1
    while n > 0:
        if n & 1 > 0:
            ret *= x
            ret %= mod
        x = (x * x) % mod
        n >>= 1
    return ret

def msum(a):
    return reduce(madd, a, 0)

n, k = map(int, input().split())
INF = - (2**60)
dp = [-INF] * (k + 1)

for g in range(k, 0, -1):
    dp[g] = msub(mpow(k // g, n), msum(dp[2 * g::g]))

print(msum([mmul(g, dp[g]) for g in range(1, k + 1)]))
