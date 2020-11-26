import sys

def dfs(row, col, table):
    table[row][col] = 0
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    for idx in range(4):
        nx = col + dx[idx]
        ny = row + dy[idx]
        if 0 <= nx < len(table[0]) and 0 <= ny < len(table) and table[ny][nx] == 1:
            dfs(ny, nx, table)

if __name__ == "__main__":
    cases = int(sys.stdin.readline())
    for _ in range(cases):
        row, col, count = list(map(int, sys.stdin.readline().split(" ")))
        table = [[0 for _ in range(col)] for _ in range(row)]

        for _ in range(count):
            r, c = list(map(int, sys.stdin.readline().split(" ")))
            table[r][c] = 1

        answer = 0
        for r in range(row):
            for c in range(col):
                if table[r][c] == 1:
                    dfs(r, c, table)
                    answer += 1

        print(answer)
