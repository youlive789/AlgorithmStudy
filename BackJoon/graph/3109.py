import sys

result = 0
move = [[-1, 1], [0, 1], [1, 1]]

def in_table(row, col, row_len, col_len):
    if row < 0 or col < 0 or row >= row_len or col >= col_len:
        return False
    else:
        return True

def print_grid(grid):
    print()
    for a in grid:
        for c in a:
            print(c, end="")
        print()

def put_pipe(row, col, grid):
    if col == len(grid[0]) - 1:
        global result
        result += 1
        return

    moved = False
    for dy, dx in move:
        row_next = row + dy
        col_next = col + dx
        if not moved and in_table(row_next, col_next, len(grid), len(grid[0])) and grid[row_next][col_next] != "x":
            moved = True
            grid[row_next][col_next] = "x"
            # print_grid(grid)
            put_pipe(row_next, col_next, grid)
    
if __name__ == "__main__":
    row, col = list(map(int, sys.stdin.readline().split(" ")))

    grid = []
    for _ in range(row):
        grid.append(list(sys.stdin.readline().replace("\n", "")))

    for r in range(row):
        put_pipe(r, 0, grid)

    print(result)