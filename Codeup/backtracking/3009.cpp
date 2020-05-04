#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int length, targetSum;

void subset(int idx, int sum, vector<int> choice) {
    if (idx == choice.size()) {
        if (sum == targetSum) {
            answer++;
        }
        return;
    }

    subset(idx + 1, sum + choice[idx], choice);
    subset(idx + 1, sum, choice);
}

int main() {

    vector<int> choice;
    cin >> length >> targetSum;

    for (int i = 0; i < length; i++)  {
        int tmp;
        cin >> tmp;
        choice.push_back(tmp);
    }
    
    subset(0, 0, choice);
    if (targetSum == 0) answer--;

    cout << answer << endl;

    return 0;
}