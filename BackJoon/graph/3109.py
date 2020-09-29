import sys

move = [[-1, 1], [0, 1], [1, 1]]

def put_pipe(row, col, grid):

    grid[row][col] = "x"
    if col == len(grid[0]) - 1:
        return True

    for dy, dx in move:
        row_next = row + dy
        col_next = col + dx
        if 0 <= row_next < len(grid) and 0 <= col_next <= len(grid[0]) and grid[row_next][col_next] != "x":
            if put_pipe(row_next, col_next, grid):
                return True
    return False
    
if __name__ == "__main__":
    row, col = list(map(int, sys.stdin.readline().split(" ")))

    grid = []
    for _ in range(row):
        grid.append(list(sys.stdin.readline().replace("\n", "")))

    result = 0
    for r in range(row):
        if put_pipe(r, 0, grid):
            result += 1

    print(result)