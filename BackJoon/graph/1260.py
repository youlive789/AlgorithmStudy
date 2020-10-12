import sys
from collections import deque

dfs_answer = []
bfs_answer = []

def dfs(node, graph, visited):
    if visited[node]:
        return 

    visited[node] = True
    dfs_answer.append(node)

    for n in graph[node]:
        dfs(n, graph, visited)

def bfs(node, graph, visited):
    q = deque([node])
    while q:
        now_node = q.popleft()
        if visited[now_node]:
            continue

        visited[now_node] = True
        bfs_answer.append(now_node)

        for n in graph[now_node]:
            if not visited[n]:
                q.append(n)

if __name__ == "__main__":
    node_count, direction_count, start_node = list(map(int, sys.stdin.readline().split(" ")))

    graph = [[] for _ in range(node_count + 1)]
    for _ in range(direction_count):
        node, to = list(map(int, sys.stdin.readline().split(" ")))
        graph[node].append(to)
        graph[to].append(node)

    for node in graph:
        node.sort()

    visited = [False for _ in range(node_count + 1)]
    dfs(start_node, graph, visited)

    visited = [False for _ in range(node_count + 1)]
    bfs(start_node, graph, visited)

    for dfs in dfs_answer:
        print(dfs, end=" ")
    print()
    for bfs in bfs_answer:
        print(bfs, end=" ")