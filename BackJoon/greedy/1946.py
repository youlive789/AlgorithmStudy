import sys

if __name__ == "__main__":
    test_case = int(sys.stdin.readline())

    for _ in range(test_case):
        count = int(sys.stdin.readline())

        table = []
        for _ in range(count):
            table.append(tuple(map(int, sys.stdin.readline().split(" "))))
        table.sort()

        answer = 1
        now_min = table[0][1]
        for i in range(count):
            if table[i][1] < now_min:
                now_min = table[i][1]
                answer += 1

        print(answer)
