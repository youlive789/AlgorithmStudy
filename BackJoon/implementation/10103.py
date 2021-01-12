count = int(input())

aa, bb = 100, 100
for _ in range(count):
    a, b = list(map(int, input().split(" ")))
    if a < b:
        aa -= b
    elif a > b:
        bb -= a

print(aa, bb)