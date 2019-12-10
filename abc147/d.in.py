import numpy as np
n = int(input())
print(n)
a = (np.random.random(n) * (2**60)).astype(int)
print(' '.join(list(map(str, a))))

