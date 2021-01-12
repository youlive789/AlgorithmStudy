import sys
import copy

maximum = -sys.maxsize
minimum = sys.maxsize

def is_count_empty(count_operators):
    for oper in count_operators:
        if oper != 0:
            return False
    return True

def calculate(idx, now_number, numbers, count_operators):
    count_operators = copy.deepcopy(count_operators)

    if idx == len(numbers) and is_count_empty(count_operators):
        global maximum, minimum
        maximum = max(maximum, now_number)
        minimum = min(minimum, now_number)
        return

    for idx_operator, count in enumerate(count_operators):
        if count > 0 :
            if idx_operator == 0:
                next_number = now_number + numbers[idx]
            elif idx_operator == 1:
                next_number = now_number - numbers[idx]
            elif idx_operator == 2:
                next_number = now_number * numbers[idx]
            else:
                next_number = int(now_number / numbers[idx])
            count_operators[idx_operator] -= 1
            calculate(idx+1, next_number, numbers, count_operators)
            count_operators[idx_operator] += 1

if __name__ == "__main__":
    count = int(sys.stdin.readline())
    numbers = list(map(int, sys.stdin.readline().split(" ")))
    count_operators = list(map(int, sys.stdin.readline().split(" ")))

    calculate(1, numbers[0], numbers, count_operators)
    print(maximum)
    print(minimum)