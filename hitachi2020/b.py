a, b, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

ans = min(A) + min(B)

for _ in range(m):
    x, y, c = map(int, input().split())
    t = A[x - 1] + B[y - 1] - c
    if t < ans:
        ans = t

print(ans)
