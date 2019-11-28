s = input()
expr = [p.split('*') for p in s.split('+')]
print(sum('0' not in e for e in expr))

