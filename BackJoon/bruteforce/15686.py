import sys
from itertools import combinations

if __name__ == "__main__":
    MAX_VAL = 99999999
    size, choose = list(map(int, sys.stdin.readline().split(" ")))

    city = []
    for _ in range(size):
        city.append(list(map(int, sys.stdin.readline().split(" "))))

    chicken = []
    distance_table = {}
    for row in range(size):
        for col in range(size):
            if city[row][col] == 1:
                distance_table[str(row)+str(col)] = MAX_VAL
            elif city[row][col] == 2:
                chicken.append(str(row)+str(col))


    result = MAX_VAL
    for i in range(1, choose + 1):
        chicken_comb = list(combinations(chicken, i))

        for comb in chicken_comb:
            now_calc = MAX_VAL
            for chicken_pos in comb:
                for house in distance_table:
                    dist = abs(int(house[0]) - int(chicken_pos[0])) + abs(int(house[1]) - int(chicken_pos[1]))
                    distance_table[house] = min(distance_table[house], dist)

                now_dist = 0
                for _, items in distance_table.items():
                    now_dist += items
                now_calc = min(now_calc, now_dist)

            result = min(result, now_calc)

            for house in distance_table:
                distance_table[house] = MAX_VAL

    print(result)
            
    

