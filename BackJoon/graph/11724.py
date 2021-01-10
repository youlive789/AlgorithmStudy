import sys
from collections import deque

sys.setrecursionlimit(10**6)
connected = 0

def dfs(idx, graph, visited):
    if visited[idx] :
        return

    visited[idx] = True

    for node in graph[idx]:
        dfs(node, graph, visited)

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
            dfs(n, graph, visited)
            connected += 1

    print(connected)
