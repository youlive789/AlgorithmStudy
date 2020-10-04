import sys
import bisect

if __name__ == "__main__":
    count_target = int(sys.stdin.readline())
    list_target = list(map(int, sys.stdin.readline().split(" ")))

    count_search = int(sys.stdin.readline())
    list_search = list(map(int, sys.stdin.readline().split(" ")))
    list_target.sort()

    result = []
    for search in list_search:
        idx_bisect = bisect.bisect_left(list_target, search)
        if idx_bisect < len(list_target) and list_target[idx_bisect] == search:
            result.append(1)
        else:
            result.append(0)

    for answer in result:
        print(answer, end=" ")