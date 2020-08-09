#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {

    int conCount;
    cin >> conCount;

    priority_queue<int, vector<int>, greater<int>> conLastDay;
    priority_queue<int, vector<int>, greater<int>> conPlan;

    for (int i = 0; i < conCount; i++) {
        int tmp;
        cin >> tmp;
        conLastDay.push(tmp);
    }

    for (int i = 0; i < conCount; i++) {
        int tmp;
        cin >> tmp;
        conPlan.push(tmp);
    }

    unsigned long long answer = 0;
    while (!conLastDay.empty()) {
        cout << conLastDay.top() << "(" << conLastDay.size() << ") " << conPlan.top() << "(" << conPlan.size() << ")" << endl;
        if (conLastDay.top() < conPlan.top()) {
            int extended = conLastDay.top() + 30;
            conLastDay.pop();
            conLastDay.push(extended);
            answer++;
        }
        else {
            conLastDay.pop();
            conPlan.pop();
        }
    }

    cout << answer << endl;

    return 0;
}