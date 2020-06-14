import numpy as np
a = np.array(list(map(int, input().split())))
for _ in range(10):
    b = [np.count_nonzero(np.abs(np.arange(len(a)) - i) <= a) for i in range(len(a))]
    print(' '.join(map(str, b)))
    a = b
