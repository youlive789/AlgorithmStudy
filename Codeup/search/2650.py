import sys

if __name__ == "__main__":
    numbers = list(map(int, sys.stdin.readline().split(" ")))
    numbers.sort()

    answer = 1
    for idx in range(1, numbers[2] + 1):
        for idx_number in range(3):
            if numbers[idx_number] % idx != 0:
                break
            if idx_number == 2:
                answer = idx

    print(answer)