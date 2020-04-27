#include <iostream>

using namespace std;

// n 라인에서 n 만큼의 별을 찍는다.
void recursionStar(int n, int cnt) {
    if (n < 1) return;

    if (n >= cnt) {
        recursionStar(n, cnt+1);
        cout << "*";
    }
    else {
        recursionStar(n-1, 1);
        if (n != 1) cout << endl;
    }
}

int main() {

    int n;
    cin >> n;

    recursionStar(n, 1);

    return 0;
}