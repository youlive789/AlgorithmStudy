#include <iostream>

using namespace std;

int container[1000000];
int question[100000];

int binarySearch(int startIdx, int endIdx, int target) {
    if (startIdx > endIdx) return -1;

    int middle = (startIdx + endIdx) / 2;
    if (target < container[middle]) {
        return binarySearch(startIdx, middle - 1, target);
    }
    else if (target > container[middle]) {
        return binarySearch(middle + 1, endIdx, target);
    }
    else {
        return middle + 1;
    }
}

int main() {

    int numContainer;
    cin >> numContainer;
    for (int i = 0; i < numContainer; i++) {
        cin >> container[i];
    }

    int numQuestion;
    cin >> numQuestion;
    for (int i = 0; i < numQuestion; i++) {
        cin >> question[i];
    }

    for (int idx = 0; idx < numQuestion; idx++) {
        cout << binarySearch(0, numContainer-1, question[idx]) << " ";
    }
    
    return 0;
}