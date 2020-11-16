import sys
from collections import deque

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    numbers = list(range(1, size+1))

    q = deque(numbers)
    while q:
        print(q.popleft(), end=" ")
        q.rotate(-1)