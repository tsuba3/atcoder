import re

n = int(input())
s = [input() for _ in range(n)]

for x in s:
    if re.match(".*okyo.*ech.*", x):
        print('Yes')
    else:
        print('No')

