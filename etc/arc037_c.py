from bisect import bisect_right

n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a.sort()
b.sort()

l = 0
r = 10 ** 18
while r - l > 1:
    x = (l + r) // 2
    s = sum([bisect_right(b, x // ax) for ax in a])
    if s < k:
        l = x
    else:
        r = x

print(r)



