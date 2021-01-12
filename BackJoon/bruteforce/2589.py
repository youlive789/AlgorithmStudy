import sys
import copy
from collections import deque

def bfs(row, col, treasure, distance):
    
    q = deque()
    q.append([row, col])

    dy = [0, 0, 1, -1]
    dx = [1, -1, 0, 0]

    answer = 0
    while q:
        r, c = q.popleft()
        answer = max(answer, distance[r][c])
        treasure[r][c] = "W"

        for idx in range(4):
            row_next = r + dy[idx]
            col_next = c + dx[idx]

            if 0 <= row_next < len(treasure) and 0 <= col_next < len(treasure[0]) and treasure[row_next][col_next] == "L" and distance[row_next][col_next] < distance[r][c]:
                q.append([row_next, col_next])
                distance[row_next][col_next] = distance[r][c] + 1
                answer = max(answer, distance[row_next][col_next])

    return answer

if __name__ == "__main__":
    
    treasure = []
    row_count, col_count = list(map(int, sys.stdin.readline().split(" ")))
    for _ in range(row_count):
        treasure.append(list(sys.stdin.readline().replace("\n", "")))

    answer = 0
    for row in range(row_count):
        for col in range(col_count):
            if treasure[row][col] == 'L':
                temp = copy.deepcopy(treasure)
                distance = [[-1 for _ in range(col_count)] for _ in range(row_count)]
                distance[row][col] = 0
                answer = max(answer, bfs(row, col, temp, distance))

    print(answer)