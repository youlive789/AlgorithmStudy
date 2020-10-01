import sys
from itertools import permutations

def calc(arr):
    result = 0
    for idx in range(len(arr) - 1):
        result += abs(arr[idx] - arr[idx + 1])
    return result

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split(" ")))

    result = 0
    comb = list(permutations(arr, size))
    for c in comb:
        result = max(result, calc(c))

    print(result)