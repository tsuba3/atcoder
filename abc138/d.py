import sys

n, q = map(int, input().split())
adj = [[] for _ in range(n)]
for _ in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    adj[a].append(b)

res = [0] * n
for _ in range(q):
    i, x = map(int, input().split())
    res[i-1] += x

parent = [0] * n
stack = [0]
while len(stack) > 0:
    i = stack.pop()
    for j in adj[i]:
        res[j] += res[i]
        stack.append(j)

print(' '.join([str(x) for x in res]))

