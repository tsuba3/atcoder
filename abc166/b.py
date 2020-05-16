import numpy as np
n, k = map(int, input().split())
a = np.zeros(n + 1)
a[0] = 1
for i in range(k):
    d = int(input())
    a[np.array(list(map(int, input().split())))] += 1
print(np.count_nonzero(a == 0))
