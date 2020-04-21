#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int cases, target;

void subset(int index, int sum, vector<int> arr) {
    if (index == arr.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }

    subset(index + 1, sum + arr[index], arr);
    subset(index + 1, sum, arr);
}

int main() {

    vector<int> arr;
    cin >> cases >> target;

    while (cases--) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    subset(0, 0, arr);
    if (target == 0) answer--;
    cout << answer << endl;

    return 0;
}