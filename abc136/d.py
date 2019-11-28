s = list(input())

odd = [0] * len(s)
even = [1] * len(s)

for i, c in enumerate(s):
    if c == 'R':
        even[i + 1] += odd[i]
        odd[i + 1] += even[i]
        odd[i] = even[i] = 0

for i in range(len(s) - 1, -1, -1):
    if s[i] == 'L':
        even[i - 1] += odd[i]
        odd[i - 1] += even[i]
        odd[i] = even[i] = 0

for i in range(len(s)):
    if s[i] == 'R':
        even[i + 1] += odd[i]

    if s[i] == 'L':
        even[i - 1] += odd[i]

print(' '.join([str(x) for x in even]))
