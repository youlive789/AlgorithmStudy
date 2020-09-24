import sys

if __name__ == "__main__":
    cnt = int(sys.stdin.readline())
    
    start_times, end_times = [], []
    for _ in range(cnt):
        start_time, end_time = list(map(int, sys.stdin.readline().split(" ")))
        start_times.append(start_time)
        end_times.append(end_time)

    start_times, end_times = zip(*sorted(list(zip(start_times, end_times)), key=lambda x: (x[1], x[0])))

    answer, end = 0, -1
    for idx in range(cnt):
        if start_times[idx] >= end:
            answer += 1
            end = end_times[idx]

    print(answer)