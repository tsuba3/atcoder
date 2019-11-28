n = int(input())
s = list(input())
RGB = 'RGB'
mod = 998244353


rgb = [0, 0, 0]
res = 1
order = [0, 1, 2]

for c in s:

    no = sorted(range(3), key = lambda i: rgb[i])

    for i in range(3):
        if order[i] != no[i]:
            rgb[i] = 0

    order = no

    i = RGB.index(c)
    rgb[i] += 1
    res *= rgb[i]
    res %= mod
    print(rgb)



print(res)

