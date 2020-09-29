import sys

if __name__ == "__main__":
    inputString = sys.stdin.readline().replace("\n", "")

    number = []
    for c in inputString:
        if c.isdigit():
            number.append(c)

    number.sort()

    target = "+".join(number)
    print(target)