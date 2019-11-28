import math
import sys
a, b, c = map(int, sys.argv[1:4])
t = float(input())
print(a * t + b * math.sin(c * t * math.pi) - 100)

