import sys
from collections import deque

if __name__ == "__main__":
    gears = []
    for _ in range(4):
        gears.append(deque(list(map(int, list(sys.stdin.readline().replace("\n", ""))))))

    rotates = []
    rotate_count = int(sys.stdin.readline())
    for _ in range(rotate_count):
        rotates.append(list(map(int, sys.stdin.readline().split(" "))))

    print(rotates)