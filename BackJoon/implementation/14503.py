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

    clean_count, is_moved, terminate = 0, False, False
    while True:
        grid[row_current][col_current] = -1
        clean_count += 1
        is_moved = False
        process(grid)

        for _ in range(4):
            direction_left_check = direction - 1
            if direction_left_check < 0:
                direction_left_check = 3

            row_left_check = row_current + dy[direction_left_check]
            col_left_check = col_current + dx[direction_left_check]
            
            direction = direction_left_check
            if 0 <= row_left_check < row and 0 <= col_left_check < col and grid[row_left_check][col_left_check] == 0:
                row_current = row_left_check
                col_current = col_left_check
                is_moved = True
                break
        
        if not is_moved:
            for _ in range(2):
                backward = direction - 2
                if backward < 0:
                    backward += 4

                if 0 <= row_current + dy[backward] < row and 0 <= col_current + dx[backward] < col and grid[row_current + dy[backward]][col_current + dx[backward]] != 1:
                    row_current += dy[backward]
                    col_current += dx[backward]
                else:
                    terminate = True
                    break

        if terminate:
            break

    print(clean_count)