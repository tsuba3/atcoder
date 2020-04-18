import numpy as np
a = np.arange(1, int(input()) + 1)
print(np.sum(np.gcd(np.gcd(a, a.reshape((-1, 1))), a.reshape((-1, 1, 1)))))
