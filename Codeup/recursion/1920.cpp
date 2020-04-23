#include <iostream>
#include <string>
#include <bits/stdc++.h> 

using namespace std;

// 문자열로 바꿔서 구현했지만 사실
// 비트 연산을 통해서 손쉽게 할 수 있을 거 같다.
void convert(int n, string target) {
    if (n == 0) {
        reverse(target.begin(), target.end());
        cout << target << endl;
        return;
    }
    target += to_string(n % 2);
    convert(n / 2, target);
}

int main() {

    int n;
    cin >> n;
    string target;

    if (n == 0) {
        cout << n << endl;
        return 0;
    }

    convert(n, target);

    return 0;
}