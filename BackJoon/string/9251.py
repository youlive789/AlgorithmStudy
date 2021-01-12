import sys

if __name__ == "__main__":
    a = list(sys.stdin.readline().replace("\n", ""))
    b = list(sys.stdin.readline().replace("\n", ""))

    cache = [[0 for _ in range(1001)] for _ in range(1001)]

    for idx_a in range(1, len(a) + 1):
        for idx_b in range(1, len(b) + 1):
            if a[idx_a - 1] == b[idx_b - 1]:
                cache[idx_a][idx_b] += cache[idx_a - 1][idx_b - 1] + 1
            else:
                cache[idx_a][idx_b] = max(cache[idx_a - 1][idx_b], cache[idx_a][idx_b - 1])

    print(cache[len(a)][len(b)])