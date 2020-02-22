n = int(input())
a = dict()
for _ in range(n):
    s = input()
    if s in a:
        a[s] += 1
    else:
        a[s] = 1

M = max(a.values())
ans = []
for s in a:
    if a[s] == M:
        ans.append(s)
ans.sort()
for s in ans:
    print(s)
