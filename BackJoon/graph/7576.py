import sys

answer = 0

def dfs(row, col, day, tomato_table):
    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]
    tomato_table[row][col] = 1

    print(row, col, day)

    result = 0
    for idx in range(4):
        row_next = row + dy[idx]
        col_next = col + dx[idx]

        if 0 <= row_next < len(tomato_table) and 0 <= col_next < len(tomato_table[0]) and tomato_table[row_next][col_next] == 0:
            dfs(row_next, col_next, day + 1, tomato_table)


if __name__ == "__main__":
    col_count, row_count = list(map(int, sys.stdin.readline().split(" ")))

    tomato_table = []
    for _ in range(row_count):
        tomato_table.append(list(map(int, sys.stdin.readline().split(" "))))

    for row in range(row_count):
        for col in range(col_count):
            if tomato_table[row][col] == 1:
                dfs(row, col, 0, tomato_table)
                
    print(answer)