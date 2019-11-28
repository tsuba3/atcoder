s = input()
s_base = int(s.replace('?', '0'))
digit = reversed(list(s))
sumd = 0
s10 = 4 # Before 1
hatena = []
for i, x in enumerate(digit):
    s10 = (10 * s10) % 13
    if x == '?':
        hatena.append(s10)
    else:
        sumd += int(x) * s10
        sumd %= 13

# sum( hatena[i] * x ) を満たすxの組み合わせを求める
mod = 10**9 + 7

dp = [[0] * 13 for _ in range(len(hatena) + 2)]
# dp[i][x] hatena[:i]の和を13で割った余りがxである整数の数
dp[0][0] = 1

for i, h in enumerate(range(len(hatena))):
    for x in range(13):
        for num in range(10):
            j = (x + num*h) % 13
            dp[i+1][j] += dp[i][x]
            dp[i+1][j] %= mod

print(dp[len(hatena)][(5-sumd)%13])
"""
print(hatena)
print(sumd)
print(dp)
"""
