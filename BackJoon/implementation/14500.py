import sys

result = 0
tetro = [
    [[0, 0], [0, 1], [0, 2], [0,3]],
    [[0, 0], [1, 0], [2, 0], [3,0]],
    
    [[0, 0], [0, 1], [1, 0], [1, 1]],

    [[0, 0], [1, 0], [2, 0], [2, 1]],
    [[0, 0], [1, 0], [0, 1], [0, 2]],
    [[0, 0], [0, 1], [1, 1], [2, 1]],
    [[0, 0], [0, 1], [0, 2], [-1, 2]],
    
    [[0, 0], [0, 1], [-1, 1], [-2, 1]],
    [[0, 0], [0, 1], [0, 2], [1, 2]],
    [[0, 0], [0, 1], [1, 0], [2, 0]],
    [[0, 0], [1, 0], [1, 1], [1, 2]],

    [[0, 0], [1, 0], [1, 1], [2, 1]],
    [[0, 0], [0, 1], [-1, 1], [-1, 2]],
    [[0, 0], [1, 0], [0, 1], [-1, 1]],
    [[0, 0], [0, 1], [1, 1], [1, 2]],

    [[0, 0], [0, 1], [0, 2], [1, 1]],
    [[0, 0], [0, 1], [1, 1], [-1, 1]],
    [[0, 0], [0, 1], [0, 2], [-1, 1]],
    [[0, 0], [1, 0], [2, 0], [1, 1]],
]

def dfs(row, col, table):
    global result
    for t in tetro:
        now_sum = 0
        for dy, dx in t:
            row_target = row + dy
            col_target = col + dx
            
            if 0 <= row_target < len(table) and 0 <= col_target < len(table[0]):
                now_sum += table[row_target][col_target]
            else:
                break
        
        if result < now_sum:
            result = now_sum

if __name__ == "__main__":
    row_size, col_size = list(map(int, sys.stdin.readline().split(" ")))
    
    table = []
    for _ in range(row_size):
        table.append(list(map(int, sys.stdin.readline().split(" "))))

    visited = [[False for _ in range(col_size)] for _ in range(row_size)]

    for row in range(row_size):
        for col in range(col_size):
            dfs(row, col, table)

    print(result)