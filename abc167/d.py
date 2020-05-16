import numpy as np
n, k = map(int, input().split())
a = []
a.append(np.array(list(map(int, input().split()))) - 1)
for _ in range(60):
    a.append(a[-1][a[-1]])
ans = 0
i = 0
while k > 0:
    if k & 1:
        ans = a[i][ans]
    i += 1
    k //= 2
print(ans + 1)
