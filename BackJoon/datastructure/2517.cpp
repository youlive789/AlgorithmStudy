#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int count;
    cin >> count;

    vector<unsigned long> runners;
    while (count--) {
        unsigned long tmp;
        cin >> tmp;
        runners.push_back(tmp);
    }

    vector<int> scores;
    for (int i = 0; i < runners.size(); ++i) {
        int score = 1;
        for (int j = 0; j < i; ++j) {
            if (runners[i] < runners[j]) {
                score++;
            }
        }
        scores.push_back(score);
    }

    for (auto score : scores) {
        cout << score << "\n";
    }

    return 0;
}