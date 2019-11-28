import itertools

n, m = map(int, input().split())
xy = set([tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(m)])

ans = 0
for i in range(1 << n):
    a = [x for x in range(n) if i & (1 << x) > 0]
    if all([(x, y) in xy for x, y in itertools.combinations(a, 2)]):
        ans = max(ans, len(a))

print(ans)

