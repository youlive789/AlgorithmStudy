from itertools import combinations

count = int(input())

for _ in range(count):
    
    wear_count = int(input())
    
    wear_dict = {}
    for _ in range(wear_count):
        wear, wear_type = input().split(" ")
        if wear_type not in wear_dict:
            wear_dict[wear_type] = []
        wear_dict[wear_type].append(wear)

    wear_number = []
    for _, wear_container in wear_dict.items():
        wear_number.append(len(wear_container))

    answer = 0
    for comb_number in range(len(wear_number), 0, -1):
        for comb in combinations(wear_number, comb_number):
            target = 1
            for c in comb:
                target *= c
            answer += target

    print(answer)
    
    