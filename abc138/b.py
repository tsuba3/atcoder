n = int(input())
a = list(map(int, input().split()))
bo = sum(map(lambda x: 1/x, a))
print(1/bo)

