#include <iostream>

using namespace std;

int cache[100000003];

int getClab(const int& number) {
    if (cache[number]) {
        return cache[number];
    }
    else {
        int clab = 0;
        int target = number;

        while (target) {
            if (cache[target]) {
                clab += cache[target];
                break;
            }
            else {
                int tmp = target % 10;
                if (tmp != 0 && tmp % 3 == 0) clab++;
                target /= 10;
            }
        }
        return cache[number] = clab;
    }
}

int conquer(const int& a, const int& b) {
    if (a == b) {
        if (cache[a]) {
            return cache[a];
        }
        else {
            return cache[a] = getClab(a);
        }
    }
    else {
        int left = conquer(a, (a + b) / 2);
        int right = conquer(((a + b) / 2) + 1, b);
        return left + right;
    }
}

int main() {

    int a, b;
    cin >> a >> b;

    cout << conquer(a, b) << endl;
    return 0;
}