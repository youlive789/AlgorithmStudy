import sys
sys.setrecursionlimit(10**6)

def dfs(row, col):
    dx = [0, 0, 1, -1, 1, -1, 1, -1]
    dy = [1, -1, 0, 0, -1, 1, 1, -1]

    board[row][col] = 0

    for idx in range(8):
        nx = col + dx[idx]
        ny = row + dy[idx]

        if 0 <= nx < len(board[0]) and 0 <= ny < len(board) and board[ny][nx] == 1:
            dfs(ny, nx)

while True:
    col_count, row_count = list(map(int, sys.stdin.readline().split(" ")))

    if col_count == 0 and row_count == 0:
        break

    board = []
    for _ in range(row_count):
        board.append(list(map(int, sys.stdin.readline().split(" "))))

    count = 0
    for row in range(row_count):
        for col in range(col_count):
            if board[row][col] != 0:
                dfs(row, col)
                count += 1

    print(count)