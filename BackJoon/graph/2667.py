import sys

area_size = 0

def dfs(row, col, block):
    block[row][col] = 0
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    global area_size
    area_size += 1

    for idx in range(4):
        row_next = row + dy[idx]
        col_next = col + dx[idx]
        if 0 <= row_next < len(block) and 0 <= col_next < len(block) and block[row_next][col_next] == 1:
            dfs(row_next, col_next, block)


if __name__ == "__main__":
    size = int(sys.stdin.readline())

    block = []
    for _ in range(size):
        block.append(list(map(int, list(sys.stdin.readline().replace("\n", "")))))

    area_count = 0
    area_size_table = []
    for row in range(size):
        for col in range(size):
            if block[row][col] == 1:
                dfs(row, col, block)
                area_count += 1
                area_size_table.append(area_size)
            area_size = 0

    print(area_count)
    area_size_table.sort()
    for area in area_size_table:
        print(area)