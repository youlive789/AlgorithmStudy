import sys
import math

if __name__ == "__main__":
    M = int(sys.stdin.readline())
    N = int(sys.stdin.readline())

    start = math.ceil(math.sqrt(M))
    end = math.floor(math.sqrt(N))

    squared = []
    for number in range(start, end + 1):
        squared.append(int(number ** 2))

    if squared:
        print(sum(squared))
        print(min(squared))
    else:
        print(-1)