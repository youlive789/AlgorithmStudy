import sys

def process(grid):
    print()
    for row in range(len(grid)):
        for col in range(len(grid[0])):
            print(grid[row][col], end=" ")
        print()

if __name__ == "__main__":
    row, col = list(map(int, sys.stdin.readline().split(" ")))
    row_current, col_current, direction = list(map(int, sys.stdin.readline().split(" ")))

    grid = []
    for _ in range(row):
        grid.append(list(map(int, sys.stdin.readline().split(" "))))

    dx = [0, 1, 0, -1]
    dy = [-1, 0, 1, 0]

    clean_count, is_moved, is_backward, terminate = 0, False, False, False
    while True:
        if not is_backward:
            grid[row_current][col_current] = "-"
            clean_count += 1
        is_moved = False
        is_backward = False

        for _ in range(4):
            direction -= 1
            if direction < 0:
                direction = 3

            row_left_check = row_current + dy[direction]
            col_left_check = col_current + dx[direction]
            
            if 0 <= row_left_check < row and 0 <= col_left_check < col and grid[row_left_check][col_left_check] == 0:
                row_current = row_left_check
                col_current = col_left_check
                is_moved = True
                break
        
        if not is_moved:
            backward = direction - 2
            if backward < 0:
                backward += 4

            row_backward = row_current + dy[backward]
            col_backword = col_current + dx[backward]

            if 0 <= row_backward < row and 0 <= col_backword < col and grid[row_backward][col_backword] != 1:
                row_current = row_backward
                col_current = col_backword
                is_backward = True
            else:
                terminate = True

        if terminate:
            break

    print(clean_count)