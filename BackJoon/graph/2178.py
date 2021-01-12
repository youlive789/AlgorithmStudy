import sys    
from collections import deque

def bfs(row, col, maze, visited):
    q = deque()
    q.append((row, col))

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    visited[row][col] = 1

    while q:
        row_now, col_now = q.popleft()

        if row_now == len(maze) - 1 and col_now == len(maze[0]) - 1:
            break

        for i in range(4):
            row_next = row_now + dy[i]
            col_next = col_now + dx[i]
            if 0 <= row_next < len(maze) and 0 <= col_next < len(maze[0]) and maze[row_next][col_next] == 1 and visited[row_now][col_now] > visited[row_next][col_next]:
                visited[row_next][col_next] = visited[row_now][col_now] + 1
                q.append((row_next, col_next))

    return visited[len(maze) - 1][len(maze[0]) - 1]

if __name__ == "__main__":
    maze = []
    row, col = list(map(int, sys.stdin.readline().split(" ")))
    for _ in range(row):
        maze.append(list(map(int, list(sys.stdin.readline().replace("\n", "")))))

    visited = [[0 for _ in range(col)] for _ in range(row)]

    print(bfs(0, 0, maze, visited))