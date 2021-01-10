import sys

if __name__ == "__main__":
    for _ in range(3):
        target = list(map(int, sys.stdin.readline().replace("\n", "")))

        last, count, now_count = -1, 0, 1
        idx, length = 0, len(target)
        while idx < length:
            if target[idx] == last:
                now_count += 1
            else:
                count = max(count, now_count)
                now_count = 1
            last = target[idx]
            idx += 1
        
        count = max(count, now_count)
        print(count)