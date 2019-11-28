n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
res = 0
for i in range(n):
    kill = min(a[i], b[i])
    b[i] -= kill
    a[i] -= kill
    
    kill2 = min(a[i+1], b[i])
    b[i] -= kill2
    a[i+1] -= kill2

    res += kill + kill2

print(res)

