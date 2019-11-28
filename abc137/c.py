from collections import Counter

n = int(input())
s = [''.join(sorted(input())) for _ in range(n)]
c = Counter(s)
ans = 0
for x in c.values():
    if x >= 2:
        ans += x*(x-1)//2

print(ans)
