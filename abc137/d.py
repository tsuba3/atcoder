n, m = list(map(int, input().split()))
ab = [list(map(int, input().split())) for _ in range(n)]
ab.sort(key=lambda x: (x[0], -x[1]))
# b 報酬

ans = 0
dp = [0] * (m+1)
for a, b in ab:


print(ans)

