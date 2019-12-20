import numpy as np
h = w = 80
a = np.round(80 * np.random.random((2 * h, w))).astype(int)
print("{} {}".format(h, w))
for line in a:
    print(' '.join(list(map(str, line))))

