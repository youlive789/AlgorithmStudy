import sys

"""
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
"""

if __name__ == "__main__":
    cnt = int(sys.stdin.readline())
    
    start_times, end_times = [], []
    for _ in range(cnt):
        start_time, end_time = list(map(int, sys.stdin.readline().split(" ")))
        start_times.append(start_time)
        end_times.append(end_time)

    start_times, end_times = zip(*sorted(list(zip(start_times, end_times)), key=lambda x: x[1]))

    idx = 0
    answer, end = 0, -1
    while idx < len(start_times):
        if start_times[idx] >= end:
            answer += 1
            end = end_times[idx]
        idx += 1

    print(answer)
    
    # result = 0
    # now_cnt = 1
    # for idx in range(cnt):
    #     now_time = end_times[idx]
    #     for idx_start in range(idx + 1, len(start_times)):
    #         if start_times[idx_start] >= now_time:
    #             now_time = end_times[idx_start]
    #             now_cnt += 1
    #     result = max(result, now_cnt)
    #     now_cnt = 1
        
    # print(result)