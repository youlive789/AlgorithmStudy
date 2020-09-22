import sys

if __name__ == "__main__":
    n, m = list(map(int, sys.stdin.readline().split(" ")))
    print((n * m) - 1)