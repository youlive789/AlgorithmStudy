import sys

def find_maxcost(now_time, now_cost, time_table, cost_table):
    if now_time > len(time_table):
        return 0

    if now_time == len(time_table):
        return now_cost

    go = find_maxcost(now_time + time_table[now_time], now_cost + cost_table[now_time], time_table, cost_table)
    notgo = find_maxcost(now_time + 1, now_cost, time_table, cost_table)
    result = max(go, notgo)

    return result

if __name__ == "__main__":
    cases = int(sys.stdin.readline())
    
    time_table = []
    cost_table = []
    for _ in range(cases):
        time, cost = list(map(int, sys.stdin.readline().split(" ")))
        time_table.append(time)
        cost_table.append(cost)

    result = find_maxcost(0, 0, time_table, cost_table)
    print(result)