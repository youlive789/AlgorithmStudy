#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    stack<int> s;
    vector<int> target;
    vector<char> answer;

    int count;
    cin >> count;

    for (int idx = 0; idx < count; idx++) {
        int tmp;
        cin >> tmp;
        target.push_back(tmp);
    }

    int number = 1, targetIdx = 0;
    while (true) {
        int sTop = s.empty() ? 0 : s.top();
        int compare = target.at(targetIdx);

        if (sTop < compare) {
            s.push(number);
            number++;
            answer.push_back('+');
        }
        else if (sTop == compare) {
            s.pop();
            targetIdx++;
            answer.push_back('-');
        }
        else {
            cout << "NO" << endl;
            exit(0);
        }

        if (s.empty() && targetIdx == count) {
            break;
        }
    }

    if (!s.empty() || targetIdx != count) {
        cout << "NO" << endl;
    }
    else {
        for (auto ans : answer) {
            cout << ans << "\n";
        }
    }

    return 0;
}