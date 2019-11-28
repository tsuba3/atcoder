n, m = map(int, input().split())
low = high = 0
lr = [tuple(map(int, input().split())) for _ in range(m)]
l = [x[0] for x in lr]
r = [x[1] for x in lr]
print(max(0, min(r) - max(l) + 1))
