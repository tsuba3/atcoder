import numpy as np
n = int(input())
a = np.array(list(map(int, input().split()))).reshape(n, 1)
mod = 10**9 + 7
bit = np.arange(64).reshape(1, 64)
b = np.sum((a >> bit) & 1, axis=0)
b *= n - b
b %= mod
b *= (1 << np.arange(64)) % mod
b %= mod
ans = 0
for x in b:
    ans += x
    ans %= mod

print(ans)

