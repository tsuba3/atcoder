import numpy as np

n, w = map(int, input().split())
a = np.array([list(map(int, input().split())) for _ in range(n)])
V = a[:, 0]
W = a[:, 1]

if n <= 30:
    n2 = n // 2

    bits = np.arange(2 ** n2)[:, np.newaxis] >> np.arange(n2) & 1
    V1 = np.sum(V[:n2] * bits, axis=1)
    W1 = np.sum(W[:n2] * bits, axis=1)
    sorted_idx = np.lexsort((V1, W1))
    V1 = V1[sorted_idx]
    W1 = W1[sorted_idx]

    bits = np.arange(2 ** (n - n // 2))[:, np.newaxis] >> np.arange(n - n // 2) & 1
    V2 = np.sum(V[n2:] * bits, axis=1)
    W2 = np.sum(W[n2:] * bits, axis=1)

    idx = np.searchsorted(W1, -1 + w - W2, side='right') - 1
    cond = idx >= 0

    ans = np.max(V1[idx[cond]] + V2[cond])

    print(ans)


