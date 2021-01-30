#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {

    queue<int> q;
    int peopleCount, rotateNumber;
    cin >> peopleCount >> rotateNumber;

    for (int idx = 1; idx <= peopleCount; idx++) {
        q.push(idx);
    }

    string answer = "<";
    while (!q.empty()) {

        int nowRotate = rotateNumber;
        while (nowRotate > 1) {
            q.push(q.front());
            q.pop();
            nowRotate--;
        }
        
        int target = q.front();
        q.pop();
        if (!q.empty()) {
            answer += to_string(target) + ", ";
        }
        else {
            answer += to_string(target) + ">";
        }
    }

    cout << answer << endl;

    return 0;
}