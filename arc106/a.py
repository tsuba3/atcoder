import numpy as np
f = [5 ** i for i in range(1, 51)]
n = int(input())
for x in range(1, 150):
    if n - 3 ** x in f:
        print(x, f.index(n - 3**x) + 1)
        exit(0)

print(-1)
