import sys
import bisect

if __name__ == "__main__":
    cnt_search = int(sys.stdin.readline())
    search = list(map(int, sys.stdin.readline().split(" ")))

    cnt_target = int(sys.stdin.readline())
    target = list(map(int, sys.stdin.readline().split(" ")))

    search.sort()

    result = []
    for t in target:
        idx_bisect = bisect.bisect_left(search, t)
        if idx_bisect < cnt_search and search[idx_bisect] == t:
            result.append(1)
        else:
            result.append(0)

    for answer in result:
        print(answer)