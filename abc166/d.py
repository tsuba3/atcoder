x = int(input())
for a in range(-400, 400):
    for b in range(-400, 400):
        if a**5 - b**5 == x:
            print('%d %d' % (a, b))
            exit(0)
