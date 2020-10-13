import sys
from collections import deque

if __name__ == "__main__":
    count, jump = list(map(int, sys.stdin.readline().split(" ")))
    circle = deque(list(range(1, count + 1)))

    answer = []
    now_jump_count = 0
    if jump != 1:
        while circle:
            if now_jump_count == jump - 1:
                answer.append(circle.popleft())
                now_jump_count = 0
            circle.rotate(-1)
            now_jump_count += 1
    else:
        answer = list(circle)

    answer_string = "<"
    for idx, num in enumerate(answer):
        answer_string += str(num)
        if idx != len(answer) - 1:
            answer_string += ", "
    answer_string += ">"
    print(answer_string)