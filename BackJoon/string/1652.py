size = int(input())

condo = []
for _ in range(size):
    condo.append(input())

# 가로개수
horizontal = 0
for row in range(size):
    target = condo[row].split("X")
    for t in target:
        if t.find("..") > -1:
            horizontal += 1

# 세로개수
vertical = 0
for col in range(size):
    target = "".join([row[col] for row in condo]).split("X")
    for t in target:
        if t.find("..") > -1:
            vertical += 1

print(horizontal, vertical)