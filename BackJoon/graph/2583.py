import sys
sys.setrecursionlimit(10**6)

def dfs(row, col, table):
    if table[row][col] == 1:
        return 1

    table[row][col] = 1

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    result = 0
    for idx in range(4):
        ny = row + dy[idx]
        nx = col + dx[idx]
        if 0 <= ny < len(table) and 0 <= nx < len(table[0]) and table[ny][nx] != 1:
            result += dfs(ny, nx, table) + 1

    return result

if __name__ == "__main__":
    row, col, square_count = list(map(int, sys.stdin.readline().split(" ")))

    table = [[0 for _ in range(col)] for _ in range(row)]

    square_positions = []
    for _ in range(square_count):
        x1, y1, x2, y2 = list(map(int, sys.stdin.readline().split(" ")))
        square_positions.append((x1, y1, x2, y2))

    for r in range(row):
        for c in range(col):
            for position in square_positions:
                x1, y1, x2, y2 = position
                x2 -= 1
                y2 -= 1
                if x1 <= c <= x2 and y1 <= r <= y2:
                    table[r][c] = 1

    answers = []
    area_count = 0
    for r in range(row):
        for c in range(col):
            if table[r][c] == 0:
                area = dfs(r, c, table)
                answers.append(area)
                area_count += 1
    
    print(area_count)
    answers.sort()
    for answer in answers:
        print(answer + 1, end=" ")