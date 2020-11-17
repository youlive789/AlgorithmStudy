import sys
sys.setrecursionlimit(10**6)

def least_common(cnt, idx, previous, numbers, cache):
    if idx == len(numbers):
        return cnt

    if cache[idx] != -1:
        return cache[idx]

    if previous < numbers[idx]:
        result = least_common(cnt+1, idx+1, numbers[idx], numbers, cache)
        result = max(result, least_common(cnt, idx+1, previous, numbers, cache))
    else:
        result = least_common(cnt, idx+1, previous, numbers, cache)

    cache[idx] = result
    return result

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    numbers = list(map(int, sys.stdin.readline().split(" ")))
    cache = [-1 for _ in range(size)]
    print(least_common(0, 0, -1, numbers, cache))

    