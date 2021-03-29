#include <iostream>
#include <vector>

using namespace std;

bool visited[32001] = {false};

void dfs(int start, vector<vector<int>> graph, vector<int>& result) {
    if (visited[start]) {
        return;
    }

    visited[start] = true;

    for (int idx = 0; idx < graph[start].size(); ++idx) {
        if (!visited[graph[start][idx]]) {
            dfs(graph[start][idx], graph, result);
        }
    }
    result.push_back(start);
}

int main() {

    int nodeCount, relCount;
    cin >> nodeCount >> relCount;

    vector<vector<int>> graph;
    for (int idx = 0; idx <= nodeCount; ++idx) {
        vector<int> tmp;
        graph.push_back(tmp);
    }

    while (relCount--) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    vector<int> result;
    for (int index = nodeCount; index >= 1; --index) {
        if (!visited[index] && graph[index].size() > 0) {
            dfs(index, graph, result);
        }
    }

    for (int idx = result.size()-1; idx >= 0; --idx) {
        cout << result[idx] << " ";
    }
    cout << endl;

    return 0;
}