import sys
from collections import deque

connected = 0

def bfs(start, graph, visited):

    global connected
    connected += 1

    q = deque([start])

    while q:
        node = q.popleft()
        visited[node] = True

        for n in graph[node]:
            if not visited[n]:
                q.append(n)

if __name__ == "__main__":
    node_count, edge_count = list(map(int, sys.stdin.readline().split(" ")))
    
    graph = [[] for _ in range(node_count + 1)]
    visited = [False for _ in range(node_count + 1)]
    for _ in range(edge_count):
        a, b = list(map(int, sys.stdin.readline().split(" ")))
        graph[a].append(b)
        graph[b].append(a)

    for n in range(1, node_count + 1):
        if not visited[n]:
            bfs(n, graph, visited)

    print(connected)
