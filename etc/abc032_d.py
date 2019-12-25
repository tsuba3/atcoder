import numpy as np

n, w = map(int, input().split())
a = np.array([list(map(int, input().split())) for _ in range(n)])
V = a[:, 0]
W = a[:, 1]

if np.max(W) <= 1000:
    Wmax = np.max(W)
    dp = np.zeros(min(w + 1, n * Wmax + 1), dtype='int64')
    for i in range(n):
        dp[W[i]:] = np.max([dp[W[i]:], dp[:-W[i]] + V[i]], axis=0)
    print(dp[min(w, dp.size - 1)])

elif np.max(V) <= 1000:
    Vmax = np.max(V)
    dp = np.repeat(1 << 60, n * Vmax + 1)
    dp[0] = 0
    for i in range(n):
        dp[V[i]:] = np.min([dp[V[i]:], dp[:-V[i]] + W[i]], axis=0)
    print(np.max(np.arange(dp.size)[dp <= w]))

elif n <= 30:
    n2 = n // 2

    bits = np.arange(2 ** n2)[:, np.newaxis] >> np.arange(n2) & 1
    V1 = np.sum(V[:n2] * bits, axis=1)
    W1 = np.sum(W[:n2] * bits, axis=1)
    W1, sorted_idx = np.unique(W1, return_index=True)
    V1 = V1[sorted_idx]
    V1 = np.maximum.accumulate(V1)

    bits = np.arange(2 ** (n - n // 2))[:, np.newaxis] >> np.arange(n - n // 2) & 1
    V2 = np.sum(V[n2:] * bits, axis=1)
    W2 = np.sum(W[n2:] * bits, axis=1)

    idx = np.searchsorted(W1, w - W2, side='right') - 1
    cond = idx >= 0

    ans = np.max(V1[idx[cond]] + V2[cond])

    print(ans)


