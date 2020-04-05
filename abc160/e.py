x, y, a, b, c = map(int, input().split())
p = list(map(int, input().split()))
p.sort()
q = list(map(int, input().split()))
q.sort()
r = list(map(int, input().split()))
print(sum(sorted(p[-x:] + q[-y:] + r)[-x-y:]))

