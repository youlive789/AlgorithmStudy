import sys

answer = 0

def dfs(idx, network, visited):
    visited[idx] = True
    for computer in network[idx]:
        if not visited[computer]:
            global answer
            answer += 1
            dfs(computer, network, visited)

if __name__ == "__main__":
    num_computer = int(sys.stdin.readline())
    num_network = int(sys.stdin.readline())
    
    network = [[] for _ in range(num_computer + 1)]
    visited = [False for _ in range(num_computer + 1)]
    for _ in range(num_network):
        a, b = list(map(int, sys.stdin.readline().split(" ")))
        network[a].append(b)
        network[b].append(a)

    dfs(1, network, visited)
    print(answer)