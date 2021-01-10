import sys

if __name__ == "__main__":
    size = int(sys.stdin.readline())

    line_info = list(map(int, sys.stdin.readline().split(" ")))
    line = [0 for _ in range(size)]

    for i in range(size):
        cnt_zeros = 0
        for j in range(size):
            if line_info[i] == cnt_zeros and line[j] == 0:
                line[j] = i+1
                break
            elif line[j] == 0:
                cnt_zeros += 1

    print(*line)