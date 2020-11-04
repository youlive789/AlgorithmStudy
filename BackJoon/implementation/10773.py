import sys

if __name__ == "__main__":
    stack = []
    cases = int(sys.stdin.readline())
    for _ in range(cases):
        number = int(sys.stdin.readline())
        if number != 0:
            stack.append(number)
        else:
            stack.pop()

    print(sum(stack))