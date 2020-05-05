#include <iostream>

using namespace std;

int answer = 0;

void remote(int diff, int cnt) {
    if (diff == 0) {
        cout << cnt << endl;
        return;
    }

    if (diff >= 8) {
        remote(diff - 10, cnt + 1);
    }
    else if (diff <= 8 && diff > 3 ) {
        remote(diff - 5, cnt + 1);
    }
    else if (diff <= 3 && diff > 0) {
        remote(diff - 1, cnt + 1);
    }   
    else if (diff < 0 && diff > -3) {
        remote(diff + 1, cnt + 1);
    }
    else if (diff <= -3 && diff > -8) {
        remote(diff + 5, cnt + 1);
    }
    else {
        remote(diff + 10, cnt + 1);
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    remote(a - b, 0);
    return 0;
}