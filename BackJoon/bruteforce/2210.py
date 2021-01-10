def dfs(row, col, number, cnt, grid, number_set):
    if cnt == 6:
        number_set.add(number)
        return

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    for idx in range(4):
        nx = col + dx[idx]
        ny = row + dy[idx]

        if 0 <= nx < len(grid[0]) and 0 <= ny < len(grid):
            dfs(ny, nx, number+str(grid[ny][nx]), cnt+1, grid, number_set)

grid = []
for _ in range(5):
    grid.append(input().split(" "))

number_set = set()
for row in range(5):
    for col in range(5):
        dfs(row, col, "", 0, grid, number_set)

print(len(number_set))