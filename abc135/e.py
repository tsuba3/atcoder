import sys

k = int(input())
x, y = map(int, input().split())
if k % 2 == 0 and (x + y) % 2 != 0:
    print(-1)
    sys.exit()


