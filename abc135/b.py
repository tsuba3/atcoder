n = int(input())
a = list(map(int, input().split()))
c = 0
for i, x in enumerate(a):
    if i + 1 != x:
        c += 1

print(['NO', 'YES'][c == 0 or c == 2])

