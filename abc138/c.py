from bisect import insort

n = int(input())
v = list(map(float, input().split()))

v.sort()
while len(v) > 1:
    x = v.pop(0)
    y = v.pop(0)
    insort(v, (x + y) / 2)

print(v[0])



