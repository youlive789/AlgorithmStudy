import sys

if __name__ == "__main__":
    number = int(sys.stdin.readline())
    cache = [-1 for _ in range(number + 1)]

    cache[1] = 0
    for idx in range(2, number + 1):
        cache[idx] = cache[idx-1] + 1
        if idx % 2 == 0:
            cache[idx] = min(cache[idx], cache[idx // 2] + 1)
        if idx % 3 == 0:
            cache[idx] = min(cache[idx], cache[idx // 3] + 1)

    print(cache[number])
