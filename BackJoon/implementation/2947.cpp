#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printWoods(const int* woods) {
    for (int i = 0; i < 5; i++) {
        cout << woods[i] << " ";
    }
    cout << endl;
}

int main() {

    int *woods = new int[5];
    for (int idx = 0; idx < 5; idx++) {
        cin >> woods[idx];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (woods[j] > woods[j+1]) {
                swap(woods[j], woods[j+1]);
                printWoods(woods);
            }
        }
    }

    return 0;
}