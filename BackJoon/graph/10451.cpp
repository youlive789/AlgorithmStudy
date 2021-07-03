#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int graph[1001];
bool visited[1001];

void bfs(int start) {
    queue<int> q;
    q.push(graph[start]);
    visited[start] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (!visited[now]) {
            visited[now] = true;
            q.push(graph[now]);
        }
    }
}

int main() {

    int caseCount;
    cin >> caseCount;

    while (caseCount--) {
        int size;
        cin >> size;

        for (int i = 1; i <= size; ++i) {
            cin >> graph[i];
        }

        int cycleCount = 0;
        for (int node = 1; node <= size; ++node) {
            if (!visited[node]) {
                bfs(node);
                cycleCount++;
            }
        }

        cout << cycleCount << endl;

        memset(graph, 0, 1001 * sizeof(int));
        memset(visited, false, 1001 * sizeof(bool));
    }

    return 0;
}