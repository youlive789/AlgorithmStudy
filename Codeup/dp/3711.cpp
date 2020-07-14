#include <iostream>

using namespace std;

int cache[100000003];

int countNumber(const int& number, const int& k) {
    if (cache[number]) {
        return cache[number];
    }
    else {
        int cnt = 0;
        int target = number;
        while (target) {

            if (cache[target]) {
                cnt += cache[target];
                break;
            }
            
            if (target % 10 == k) cnt++;
            target /= 10;
        }
        if (number == 0 && k == 0) cnt++;

        return cache[number] = cnt;
    }
}

int find(const int& a, const int& b, const int& k) {
    if (a == b) {
        return countNumber(a, k);
    }
    else {
        int half = (a + b) / 2;
        int left = find(a, half, k);
        int right = find(half + 1, b, k);
        return left + right;
    }
}

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    cout << find(a, b, k) << endl;
    return 0;
}