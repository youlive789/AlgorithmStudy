import sys
from collections import deque

normal = 0
colorblind = 0

def bfs(row, col, graph, visited):
    q = deque()
    q.append((row, col))

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    while q:
        row, col = q.popleft()
        visited[row][col] = True

        for idx in range(4):
            nx = col + dx[idx]
            ny = row + dy[idx]

            if 0 <= nx < len(graph[0]) and 0 <= ny < len(graph) and not visited[ny][nx] and graph[ny][nx] == graph[row][col]:
                q.append((ny, nx))

if __name__ == "__main__":
    graph = []
    size = int(sys.stdin.readline())
    for _ in range(size):
        graph.append(list(sys.stdin.readline().replace("\n", "")))

    visited = [[False for _ in range(size)] for _ in range(size)]
    for row in range(size):
        for col in range(size):
            if not visited[row][col]:
                bfs(row, col, graph, visited)
                normal += 1

    for row in range(size):
        for col in range(size):
            if graph[row][col] == "G":
                graph[row][col] = "R"

    visited = [[False for _ in range(size)] for _ in range(size)]
    for row in range(size):
        for col in range(size):
            if not visited[row][col]:
                bfs(row, col, graph, visited)
                colorblind += 1

    print(normal, colorblind)