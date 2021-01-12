import sys
import math
import copy
from itertools import combinations

def virus(table):
    for row in range(len(table)):
        for col in range(len(table[0])):
            if table[row][col] == 2:
                go_virus(row, col, table)
    
def go_virus(row, col, table):

    table[row][col] = 2
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    for idx in range(4):
        row_next = row + dy[idx]
        col_next = col + dx[idx]
        if 0 <= row_next < len(table) and 0 <= col_next < len(table[0]) and table[row_next][col_next] == 0:
            go_virus(row_next, col_next, table)

if __name__ == "__main__":
    row, col = list(map(int, sys.stdin.readline().split(" ")))

    table, wall_position = [], []
    for row in range(row):
        position = list(map(int, sys.stdin.readline().split(" ")))
        table.append(position)

    for row in range(len(table)):
        for col in range(len(table[0])):
            if table[row][col] == 0:
                wall_position.append([row, col])

    result = -math.inf

    # 0인 지점에 차례대로 벽을 세운다.
    wall_combination = list(combinations(wall_position, 3))
    for wall_comb in wall_combination:
        test_table = copy.deepcopy(table)

        # 벽 설정
        for row, col in wall_comb:
            test_table[row][col] = 1

        # 바이러스를 퍼뜨린다.
        virus(test_table)

        # 안전영역을 계산한다.
        cnt = 0
        for r in range(len(test_table)):
            for c in range(len(test_table[0])):
                if test_table[r][c] == 0:
                    cnt += 1

        if result < cnt:
            result = cnt

    print(result)