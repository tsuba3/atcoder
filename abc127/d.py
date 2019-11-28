from bisect import bisect_right

n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
a.sort()
bc = [list(map(int, input().split())) for _ in range(m)]
bc.sort(key=lambda x: x[1], reverse=True)

res = 0
fin = 0
for b, c in bc:
    count = bisect_right(a, c, lo=fin, hi=min(fin+b, len(a))) - fin
    fin += count
    res += count * c
for i in range(fin, len(a)):
    res += a[i]

print(res)
