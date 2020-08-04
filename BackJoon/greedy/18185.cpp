#include <iostream>

using namespace std;

int factory[10002];

int main() {

    int factoryNumber;
    cin >> factoryNumber;

    for (int i = 0; i < factoryNumber; i++) {
        int tmp;
        cin >> tmp;
        factory[i] = tmp;
    }

    int index = 0, answer = 0, count = 0;
    while (index < factoryNumber) {

        if (factory[index+1] > factory[index+2]) {
            // index + 1 까지 숫자가 있다면
            count = min(factory[index], factory[index + 1] - factory[index + 2]);
            factory[index] -= count;
            factory[index+1] -= count;
            answer += 5 * count;
            

            // index + 2 까지 숫자가 있다면
            count = min(factory[index], min(factory[index + 1], factory[index + 2]));
            factory[index] -= count;
            factory[index+1] -= count;
            factory[index+2] -= count;
            answer += 7 * count;
            
        }
        else {
            // index + 2 까지 숫자가 있다면
            count = min(factory[index], min(factory[index + 1], factory[index + 2]));
            factory[index] -= count;
            factory[index+1] -= count;
            factory[index+2] -= count;
            answer += 7 * count;

            // index + 1 까지 숫자가 있다면
            count = min(factory[index], factory[index + 1]);
            factory[index] -= count;
            factory[index+1] -= count;
            answer += 5 * count;
        }

        // 현재 위치에만 숫자가 있다면
        count = 0;
        answer += 3 * factory[index];
        index++;
    }

    cout << answer << endl;

    return 0;
}
