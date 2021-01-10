from itertools import combinations

container = []
for _ in range(9):
    container.append(int(input()))

for comb in combinations(container, 7):
    if sum(comb) == 100:
        temp = list(comb)
        for item in temp:
            print(item)
        exit()