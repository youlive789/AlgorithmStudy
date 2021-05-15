#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

bool visited[201] = {false};

int getLinkScore(int user, int target, map<int, vector<int>> link) {
    
    int score = 0;
    
    queue<pair<int, int>> q;
    q.push(make_pair(user, score));

    while (!q.empty()) {

        int search = q.front().first;
        int nowScore = q.front().second;
        q.pop();

        if (search == target) {
            score = nowScore;
            break;
        }

        for (auto l : link[search]) {
            if (!visited[l]) {
                q.push(make_pair(l, nowScore + 1));
            }
        }
    }

    memset(visited, false, sizeof(visited));
    return score;
}

int main() {

    int totalCount, linkCount;
    cin >> totalCount >> linkCount;

    map<int, vector<int>> link;
    for (int i = 1; i <= totalCount; i++) {
        vector<int> container;
        link[i] = container;
    }

    while (linkCount--) {
        int user, linkTarget;
        cin >> user >> linkTarget;
        link[user].push_back(linkTarget);
        link[linkTarget].push_back(user);
    }

    int answerUser = 0, baconScore = INT32_MAX;
    for (int user = 1; user <= totalCount; ++user) {
        int tmpScore = 0;
        for (int targetUser = 1; targetUser <= totalCount; ++targetUser) {
            if (user == targetUser) continue;
            int result = getLinkScore(user, targetUser, link);
            tmpScore += result;
        }

        if (baconScore > tmpScore) {
            answerUser = user;
            baconScore = tmpScore;
        }
    }

    cout << answerUser << endl;
    
}