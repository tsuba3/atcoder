n = int(input())
xy = [list(map(int, input().split())) for _ in range(n)]
xy.sort(key=lambda x: x[0])
y = list(range(n))
y.sort(key=lambda i: xy[i][1])

mod = 998244353  # Prime

total = (3 ** n - 1) // 2
diff = (abs(sum([abs(x - i) for i, x in enumerate(y)]) - sum([abs(x-i) for i, x in enumerate(reversed(range(n)))])) ) ** n
print(total)
print(diff)
print((total - diff) % mod)

# 6
# 29524 36