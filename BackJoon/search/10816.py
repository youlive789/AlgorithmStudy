import sys
from collections import Counter

if __name__ == "__main__":
    cnt = int(sys.stdin.readline())
    counter = Counter(list(map(int, sys.stdin.readline().split(" "))))

    cases = int(sys.stdin.readline())
    target = list(map(int, sys.stdin.readline().split(" ")))

    for ele in target:
        print(counter[ele], end=" ")