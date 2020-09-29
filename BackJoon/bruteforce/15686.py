import sys
import math
from itertools import combinations

def get_distance(comb_chicken, house):
    dist = 0
    for row_house, col_house in house:
        house_dist, now_house_dist = math.inf, 0
        for row_chicken, col_chicken in comb_chicken:
            now_house_dist = abs(row_house - row_chicken) + abs(col_house - col_chicken)
            if now_house_dist < house_dist:
                house_dist = now_house_dist
        dist += house_dist
    return dist

if __name__ == "__main__":
    
    # 집과 치킨집의 위치정보를 저장한다.
    house, chicken = [], []
    N, M = list(map(int, sys.stdin.readline().split(" ")))
    for row in range(N):
        position = list(map(int, sys.stdin.readline().split(" ")))
        for col in range(N):
            if position[col] == 1:
                house.append([row, col])
            elif position[col] == 2:
                chicken.append([row, col])

    comb_chicken = list(combinations(chicken, M))
    
    result = math.inf
    for comb in comb_chicken:
        dist = get_distance(comb, house)
        if dist < result:
            result = dist

    print(result)

    

