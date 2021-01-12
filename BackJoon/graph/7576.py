import sys
from collections import deque

answer = 0

def print_table(tomato_table):
    print()
    for row in range(row_count):
        for col in range(col_count):
            print(tomato_table[row][col], end=" ")
        print()  

def bfs(tomato_positions, day, tomato_table, days):
    q = deque(tomato_positions)
    
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]

    while q:
        r, c = q.popleft()
        tomato_table[r][c] = 1

        global answer
        answer = max(answer, days[r][c])

        for idx in range(4):
            row_next = r + dy[idx]
            col_next = c + dx[idx]

            if 0 <= row_next < len(tomato_table) and 0 <= col_next < len(tomato_table[0]) and tomato_table[row_next][col_next] == 0 and days[r][c] > days[row_next][col_next]:
                days[row_next][col_next] = days[r][c] + 1
                q.append([row_next, col_next])


if __name__ == "__main__":
    col_count, row_count = list(map(int, sys.stdin.readline().split(" ")))

    tomato_table = []
    for _ in range(row_count):
        tomato_table.append(list(map(int, sys.stdin.readline().split(" "))))

    days = [[-1 for _ in range(col_count)] for _ in range(row_count)]

    # 토마토의 위치 저장
    tomato_positions = []
    for row in range(row_count):
        for col in range(col_count):
            if tomato_table[row][col] == 1:
                tomato_positions.append([row, col])
                days[row][col] = 0

    bfs(tomato_positions, 0, tomato_table, days)
                
    # 익지 않은 토마토 탐색
    for row in range(row_count):
        for col in range(col_count):
            if tomato_table[row][col] == 0:
                print(-1)
                quit()

    print(answer)