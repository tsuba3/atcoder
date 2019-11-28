from bisect import bisect_left

n, m = map(int, input().split())
py = [tuple(map(int, input().split())) for _ in range(m)]
pym = {}
for i, (p, y) in enumerate(py):
    if p not in pym:
        pym[p] = []
    pym[p].append(y)

for p, yy in pym.items():
    yy.sort()

for (p, y) in py:
    ps = ('000000' + str(p))[-6:]
    ys = ('000000' + str(bisect_left(pym[p], y) + 1))[-6:]
    print(ps+ys)

