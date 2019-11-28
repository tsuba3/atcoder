a, b = map(int, input().split())
x = abs(a-b)
if x % 2 == 0:
    print(x//2 + min(a, b))
else:
    print('IMPOSSIBLE')
