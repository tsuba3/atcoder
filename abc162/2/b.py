import numpy as np
a = np.arange(1, int(input()) + 1)
print(np.sum(a[np.logical_and(a % 3 != 0, a % 5 != 0)]))
