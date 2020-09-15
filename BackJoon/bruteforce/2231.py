import sys

def calc(num):
    result = num
    while num:
        result += num % 10
        num //= 10
    return result

if __name__ == "__main__":
    target = int(sys.stdin.readline())

    for num in range(1, target + 1):
        c = calc(num)
        if c == target:
            print(num)
            exit()

    print(0)