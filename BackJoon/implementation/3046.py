import sys

if __name__ == "__main__":
    r1, s = list(map(int, sys.stdin.readline().split(" ")))
    r2 = 2 * s - r1
    print(r2)