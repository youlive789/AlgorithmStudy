#include <iostream>

using namespace std;

int cache[100000003];

int getClab(const int& number) {
    int clab = 0;
    int target = number;
    while (target) {
        if (cache[target] && cache[target] != number) {
            clab += cache[target];
            break;
        }
        else {
            if (target % 10 == 3 || target % 10 == 6 || target % 10 == 9) clab++;
            target /= 10;
        }
    }
    return cache[target] = clab;
}

int game(const int& a, const int& b) {
    int answer = 0;
    for (int idx = a; idx <= b; idx++) {
        answer += getClab(idx);
    }
    return answer;
}

int main() {

    int a, b;
    cin >> a >> b;

    cout << game(a, b) << endl;

    return 0;
}