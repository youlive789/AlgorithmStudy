import sys
import bisect

if __name__ == "__main__":
    count, k = list(map(int, sys.stdin.readline().split(" ")))
    numbers = list(map(int, sys.stdin.readline().split(" ")))

    numbers.sort()
    print(numbers[k-1])