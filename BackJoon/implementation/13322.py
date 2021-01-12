string = input()

container = []
for limit in range(len(string), 0, -1):
    container.append(limit)

for index in range(len(container)-1, -1, -1):
    limit = container[index]
    print(limit-1)
