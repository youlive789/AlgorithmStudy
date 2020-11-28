import sys
from collections import deque

if __name__ == "__main__":
    bracket = sys.stdin.readline().replace("\n", "")
    q = deque(bracket)

    answer = 10
    last = q.popleft()
    while q:
        now = q.popleft()
        if now != last:
            answer += 10
        else:
            answer += 5
        last = now

    print(answer)