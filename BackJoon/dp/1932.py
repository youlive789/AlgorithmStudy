import sys
sys.setrecursionlimit(10**6)

def find_sum(idx_row, idx_selected, triangle, cache):
    if idx_row == len(triangle):
        return 0

    if cache[idx_row][idx_selected] != 0:
        return cache[idx_row][idx_selected]
    else:
        result = 0
        for idx in range(len(triangle[idx_row])):
            if idx_selected <= idx <= idx_selected + 1:
                result = max(result, find_sum(idx_row + 1, idx, triangle, cache) + triangle[idx_row][idx])
        cache[idx_row][idx_selected] = result
        return result

if __name__ == "__main__":
    size = int(sys.stdin.readline())

    triangle = []
    for _ in range(size):
        temp = list(map(int, sys.stdin.readline().split(" ")))
        triangle.append(temp)

    cache = [[0 for _ in range(len(triangle))] for _ in range(len(triangle))]

    print(find_sum(0, 0, triangle, cache))
