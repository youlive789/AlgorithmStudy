target = input()
for sep in range(1, len(target)):
    front = target[0:sep] 
    back = target[sep:]

    front_multiply = 1
    for num in front:
        front_multiply *= int(num)

    back_multiply = 1
    for num in back:
        back_multiply *= int(num)

    if front_multiply == back_multiply:
        print("YES")
        exit()

print("NO")