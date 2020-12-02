import sys
import math
from itertools import combinations_with_replacement

def check_triangle(target, triangle):
    for comb in combinations_with_replacement(triangle, 3):
        if target == sum(comb):
            print(1)
            return
    print(0)
    return

if __name__ == "__main__":
    triangle = [(num * (num + 1) // 2) for num in range(1, 101)]

    cases = int(sys.stdin.readline())
    for _ in range(cases):
        target = int(sys.stdin.readline())
        check_triangle(target, triangle)
