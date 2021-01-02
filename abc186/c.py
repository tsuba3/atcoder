import numpy as np

n = int(input())

a = np.arange(1, n + 1).reshape(-1, 1)
d8 = np.any((a // (8 ** np.arange(6))) % 8 == 7, axis=1)
d10 = np.any((a // (10 ** np.arange(5))) % 10 == 7, axis=1)
print(n - np.count_nonzero(np.logical_or(d8, d10)))

