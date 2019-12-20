import numpy as np
n = int(input())
print(n)
a = np.random.randint(0, 2**60, n)
print(' '.join(list(map(str, a))))

