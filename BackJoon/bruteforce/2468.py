import sys

sys.setrecursionlimit(10 ** 6)

def dfs(row, col, limit_height, table, visited):
    if visited[row][col]:
        return

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    visited[row][col] = True
    for idx in range(4):
        row_next = row + dy[idx]
        col_next = col + dx[idx]
        if 0 <= row_next < len(table) and 0 <= col_next < len(table[0]) and table[row_next][col_next] > limit_height:
            dfs(row_next, col_next, limit_height, table, visited)

if __name__ == "__main__":
    size = int(sys.stdin.readline())

    table, max_height = [], 0
    for _ in range(size):
        row = list(map(int, sys.stdin.readline().split(" ")))
        if max(row) > max_height:
            max_height = max(row)
        table.append(row)

    result = 0
    for height in range(max_height, -1, -1):
        now_area = 0
        visited = [[False for _ in range(size)] for _ in range(size)]
        for row in range(size):
            for col in range(size):
                if not visited[row][col] and table[row][col] > height:
                    dfs(row, col, height, table, visited)
                    now_area += 1
        result = max(now_area, result)
        now_area = 0

    print(result)
