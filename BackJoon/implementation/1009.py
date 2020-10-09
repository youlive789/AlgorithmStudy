import sys
import math

if __name__ == "__main__":
    cases = int(sys.stdin.readline())

    answer = []
    num_table = {
        0 : [0],
        1 : [1],
        2 : [2, 4, 8, 6],
        3 : [3, 9, 7, 1],
        4 : [4, 6],
        5 : [5],
        6 : [6],
        7 : [7, 9, 3, 1],
        8 : [8, 4, 2, 6],
        9 : [9, 1]
    }

    for _ in range(cases):
        a, b = list(map(int, sys.stdin.readline().split(" ")))
        a %= 10

        target_index = (b % len(num_table[a])) - 1
        answer.append(num_table[a][target_index] % 10)
    
    for a in answer:
        if a == 0:
            print(10)
        else:
            print(a)