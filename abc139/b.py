a, b = map(int, input().split())
port = 1
ans = 0
while port < b:
    port += a - 1
    ans += 1
print(ans)

