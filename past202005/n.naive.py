n, q = map(int, input().split())
a = list(range(1, n + 1))
for _ in range(q):
    t, x, y = map(int, input().split())
    x -= 1
    y -= 1
    if t == 1:
        a[x], a[x + 1] = a[x + 1], a[x]
    else:
        a[x:y+1] = sorted(a[x:y+1])
        print(' '.join(map(str, a)))
print(' '.join(map(str, a)))
