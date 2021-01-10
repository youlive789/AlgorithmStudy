import sys
from collections import Counter

if __name__ == "__main__":
    binary = list(map(int, list(sys.stdin.readline().replace("\n", ""))))

    answer = [0, 0]

    last = binary[0]
    for idx in range(1, len(binary)):
        if binary[idx] != last:
            if last == 1:
                answer[1] += 1
            else:
                answer[0] += 1
        last = binary[idx]

    if binary[-1] == 0:
        answer[0] += 1
    else:
        answer[1] += 1

    print(min(answer))