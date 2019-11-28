n = int(input())
a = [int(input()) for _ in range(n)]
s = sorted(a)
for x in a:
    if s[-1] == x:
        print(s[-2])
    else:
        print(s[-1])