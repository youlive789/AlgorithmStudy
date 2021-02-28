#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(int searchStart, int searchEnd, vector<vector<int>> graph, bool visited[101], int count) {
    if (searchStart == searchEnd) return count;
    
    int answer = -1;

    visited[searchStart] = true;
    for (int i = 0; i < graph.at(searchStart).size(); ++i) {
        if (!visited[graph.at(searchStart).at(i)]) {
            answer = max(search(graph.at(searchStart).at(i), searchEnd, graph, visited, count+1), answer);
        }
    }
    return answer;
}

int main() {

    bool visited[101] = {false};
    vector<vector<int>> graph;

    int famliyCount;
    cin >> famliyCount;

    int searchStart, searchEnd;
    cin >> searchStart >> searchEnd;

    int nodeCount;
    cin >> nodeCount;

    for (int i = 0; i <= famliyCount; ++i) {
        vector<int> temp;
        graph.push_back(temp);
    }

    for (int i = 0; i < nodeCount; ++i) {
        int nodeStart, nodeEnd;
        cin >> nodeStart >> nodeEnd;

        graph.at(nodeStart).push_back(nodeEnd);
        graph.at(nodeEnd).push_back(nodeStart);
    }

    int answer = search(searchStart, searchEnd, graph, visited, 0);
    cout << answer << endl;

    return 0;
}