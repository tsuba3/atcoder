s = input()

res = 1
i = 1
prev = s[0]
while i < len(s):
    if s[i] == prev:
        prev = s[i:i+2]
        i += 2
        if i + 2 < len(s):
            res += 1
    else:
        prev = s[i]
        i += 1
        res += 1


print(res)

