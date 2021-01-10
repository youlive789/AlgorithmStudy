import sys

cache = [-1] * 1001
sys.setrecursionlimit(10**6)

def fill(length):
    if length < 0:
        return 0

    if cache[length] != -1:
        return cache[length]
    else:
        if length == 0:
            return 1

        cache[length] = fill(length - 1) + fill(length - 2) + fill(length - 2)
        return cache[length]

if __name__ == "__main__":
    length = int(sys.stdin.readline())

    print(fill(length) % 10007)