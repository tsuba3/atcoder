n = int(input())
h = list(map(int, input().split()))


def f():
    prev = h[0] - 1
    for i in range(1, n):
        if prev > h[i]:
            return False
        prev = max(prev, h[i]-1)
    return True


print(['No', 'Yes'][f()])
