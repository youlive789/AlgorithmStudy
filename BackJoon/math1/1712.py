import sys

if __name__ == "__main__":
    a, b, c = list(map(int, sys.stdin.readline().split(" ")))
    if c - b <= 0:
        print(-1)
    else:
        a /= (c - b)
        a = int(a)
        print(a + 1)