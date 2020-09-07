#include <iostream>
#include <vector>
#include <queue>

#define MAX 20010
#define INF 987654321

using namespace std;

int v, e, start;
int dist[MAX];
vector<pair<int, int>> graph[MAX];

void make_graph() {
    cin >> v >> e >> start;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    for (int i = 1; i <= v; i++) {
        dist[i] = INF;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    make_graph();

    // (길이, 노드)
    priority_queue<pair<int, int>> queue;
    queue.push(make_pair(0, start));
    dist[start] = 0;

    while (queue.empty() == 0) {
        int cost = -queue.top().first;
        int currentNode = queue.top().second;
        queue.pop();

        for (int i = 0; i < graph[currentNode].size(); i++) {
            int next = graph[currentNode][i].first;
            int nextCost = graph[currentNode][i].second;

            if (dist[next] > cost + nextCost) {
                dist[next] = cost + nextCost;
                queue.push(make_pair(-dist[next], next));
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) {
            cout << "INF" << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}