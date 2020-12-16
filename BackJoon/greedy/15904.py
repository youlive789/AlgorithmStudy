string = input()
check = list("UCPC")

idx_check = 0
for char in string:
    if idx_check < 4 and char == check[idx_check]:
        idx_check += 1

if idx_check != 4:
    print("I hate UCPC")
else:
    print("I love UCPC")
