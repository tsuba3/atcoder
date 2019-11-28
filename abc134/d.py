n = int(input())
a = list(map(int, input().split()))
b = [False] * n
for i in range(n - 1, -1, -1):
    if sum(b[i::i+1]) % 2 != a[i]:
        b[i] = True
res = [str(x + 1) for x, v in enumerate(b) if v]
print(len(res))
if len(res) > 0:
    print(' '.join(res))
