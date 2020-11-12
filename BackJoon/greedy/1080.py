import sys
from operator import xor

def is_same(target, row_count, col_count):
    for row in range(row_count):
        for col in range(col_count):
            if target[row][col] != 0:
                return False
    return True

def flip_list(row, col, target_list):
    if row + 2 >= len(target_list) or col + 2 >= len(target_list[0]):
        return False

    for r in range(row, row + 3):
        for c in range(col, col + 3):
            target_list[r][c] ^= 1

    return True

if __name__ == "__main__":
    row_count, col_count = list(map(int, sys.stdin.readline().split(" ")))

    A, B = [], []
    for idx in range(2):
        if idx == 0:
            for _ in range(row_count):
                A.append(list(map(int, list(sys.stdin.readline().replace("\n", "")) )))
        else:
            for _ in range(row_count):
                B.append(list(map(int, list(sys.stdin.readline().replace("\n", "")) )))

    temp = []
    for row in range(row_count):
        temp.append([])
        for col in range(col_count):
            temp[row].append(A[row][col] ^ B[row][col])

    count = 0
    for row in range(row_count):
        for col in range(col_count):
            if flip_list(row, col, temp):
                count += 1

    same = is_same(temp, row_count, col_count)
    if same:
        print(count)
    elif not same and count == 0:
        print(count)
    else:
        print(-1)