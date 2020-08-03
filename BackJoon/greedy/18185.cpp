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

    int index = 0, answer = 0;
    while (index < factoryNumber) {
        // index + 2 까지 숫자가 있다면
        if (factory[index] && factory[index+1] && factory[index+2]) {
            factory[index]--;
            factory[index+1]--;
            factory[index+2]--;
            answer += 7;
        }
            
        // index + 1 까지 숫자가 있다면
        if (factory[index] && factory[index+1]) {
            factory[index]--;
            factory[index+1]--;
            answer += 5;
        }
            
        // 현재 위치에만 숫자가 있다면
        if (factory[index]) {
            factory[index]--;
            answer += 3;
        }

        // 현재 위치에 숫자가 없다면
        if (!factory[index]) {
            index++;
        }
    }

    cout << answer << endl;

    return 0;
}