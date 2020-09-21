import sys

if __name__ == "__main__":
    cases = int(sys.stdin.readline())
    
    time_table = []
    cost_table = []
    for _ in range(cases):
        time, cost = list(map(int, sys.stdin.readline().split(" ")))
        time_table.append(time)
        cost_table.append(cost)

    