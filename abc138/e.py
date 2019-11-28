import sys

s = input()
t = input()

si = 0
ti = 0

res = []

if not set(s) >= set(t):
    print(-1)
    sys.exit(0)


while ti < len(t):
    if s[si % len(s)] == t[ti]:
        si += 1
        ti += 1
    else:
        si += 1

print(si)


