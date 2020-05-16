import numpy as np
from collections import Counter
n = int(input())
i = np.arange(n)
a = np.array(list(map(int, input().split())))
p = i + a
m = i - a
pc = Counter(p)
mc = Counter(m)
ans = sum([cnt * mc[x] for x, cnt in pc.items()])
print(ans)
