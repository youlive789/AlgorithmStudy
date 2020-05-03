#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nine[9];

void choose(vector<int> choice, int idx, int sum) {
    
    // 기저사례: 끝까지 탐색하고 합이 100 이라면
    if (choice.size() == 7) {
        if (sum == 100) {
            sort(choice.begin(), choice.end());
            for (int num : choice) {
                cout << num << endl;
            }
            return;
        }
        else {
            return;
        }
    }

    if (idx == 0 && sum == 0) {
        idx = 0;
    }
    else {
        idx++;
    }

    for (int i = idx; i < 9; i++) {
        choice.push_back(nine[i]);
        choose(choice, i, sum + nine[i]);
        choice.pop_back();
    }
}

int main() {

    for (int i = 0; i < 9; i++) {
        int tmp;
        cin >> tmp;
        nine[i] = tmp;
    }

    vector<int> choice;
    choose(choice, 0, 0);

    return 0;
}