import sys

if __name__ == "__main__":
    a = list(sys.stdin.readline().replace("\n", ""))
    b = list(sys.stdin.readline().replace("\n", ""))

    idx_a = 0
    idx_b = 0

    res = 0
    while idx_a < len(a) and idx_b < len(b):
        if a[idx_a] != b[idx_b]:
            if idx_b == len(b) - 1:
                idx_a += 1
            else:
                idx_b += 1
        else:
            print(idx_a, idx_b)
            res += 1
            idx_a += 1
            idx_b += 1
    print()
    print(res)