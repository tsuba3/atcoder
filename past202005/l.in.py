import random
n = 10 ** 5
print(n)
for _ in range(n):
    print(' '.join(map(str, [3, *[random.randint(1, 10**9) for _ in range(3)]])))
m = 3 * 10 ** 5
print(m)
print(' '.join(map(str, [random.randint(1, 2) for _ in range(m)])))
