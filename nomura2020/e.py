t = input()
def f(s):
    if len(s) == 0:
        return 0
    x = sum(map(int, s[::2]))
    k = max([f(s[:i] + s[i+1:]) for i in range(len(s))])
    return x + k
print(f(t))
