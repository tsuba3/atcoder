def make_divisors(n):
    divisors = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n // i)

    divisors.sort(reverse=True)
    return divisors


n, k = list(map(int, input().split()))
a = list(map(int, input().split()))

div = make_divisors(sum(a))

for x in div:
    aa = [ai % x for ai in a]
    aa.sort()
    ss = aa[:len(aa) - sum(aa) // x]
    s = sum(ss)

    if 0 <= s <= k:
        print(x)
        break

# 2 | 3 5 | 8 _ 3
# 3 | 3 1 2 1 | 7 _ 4
# 4 | 1 2 0 1 3 2 1 0 | 10 _ 5
