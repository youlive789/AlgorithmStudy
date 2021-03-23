#include <iostream>
#include <vector>

using namespace std;

bool visited[32001] = {false};

void dfs(int start, vector<vector<int>> graph, vector<int> result) {
    visited[start] = true;

    for (int idx = 0; idx < graph[start].size(); ++idx) {
        if (!visited[graph[start][idx]] && graph[graph[start][idx]].size() > 0) {
            dfs(graph[start][idx], graph, result);
            result.push_back(graph[start][idx]);
        }
    }
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
    for (int index = 1; index <= nodeCount; ++index) {
        if (!visited[index] && graph[index].size() > 0) {
            dfs(index, graph, result);
            result.push_back(index);
        }
    }

    for (auto ele : result) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}