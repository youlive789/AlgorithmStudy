import sys

if __name__ == "__main__":
    total = int(sys.stdin.readline())
    for _ in range(9):
        total -= int(sys.stdin.readline())

    print(total)