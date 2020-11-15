x, y, a, b = list(map(int, input().split()))

ans = 0
while (x * a < x + b and x * a < y):
    ans += 1
    x *= a

ans += (y - x - 1) // b
print(ans)

