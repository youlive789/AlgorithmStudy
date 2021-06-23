#include <iostream>

using namespace std;

int container[1001];

int main() {

    int start, end;
    cin >> start >> end;

    int index = 1;
    int number = 1, accumulator = 1;
    while (index <= end) {
        container[index] = number;
        accumulator--;

        if (accumulator == 0) {
            number++;
            accumulator = number;
        }
        
        index++;
    }

    int sum = 0;
    for (int idx = start; idx <= end; ++idx) {
        sum += container[idx];
    }

    cout << sum << endl;

    return 0;
}