import sys
sys.setrecursionlimit(10**6)

def least_common(cnt, idx, last_idx, numbers, cache):
    if idx == len(numbers):
        return cnt

    if cache[idx][last_idx] != -1:
        return cache[idx][last_idx]

    last = 0
    if last != -1:
        last = numbers[last]

    left, right = 0, 0
    if last < numbers[idx]:
        left = least_common(cnt+1, idx+1, idx, numbers, cache)
    right = least_common(cnt, idx+1, last_idx, numbers, cache)

    cache[idx][last_idx] = max(left, right)
    return cache[idx][last_idx]

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    numbers = list(map(int, sys.stdin.readline().split(" ")))
    cache = [[-1 for _ in range(size)] for _ in range(size)]

    print(least_common(0, 0, -1, numbers, cache))