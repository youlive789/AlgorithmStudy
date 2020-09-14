import sys

def factorial(num):
    if num == 1 or num == 0:
        return 1

    return factorial(num - 1) * num

if __name__ == "__main__":
    num = int(sys.stdin.readline())
    print(factorial(num))