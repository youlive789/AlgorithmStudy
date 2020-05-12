#include <iostream>

using namespace std;

int answer = 0;
int pos[10][10] = {-1};
bool col[10];

void candy(int cnt, int N, int sum) {
    if (cnt == N) {
        if (answer < sum) {
            answer = sum;
        }
        return;
    }

    for (int idx = 0; idx < N; idx++) {
        if (col[idx]) {
            col[idx] = false;
            candy(cnt + 1, N, sum + pos[cnt][idx]);
            col[idx] = true;
        }
    }
}

int main() {

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp; 
            pos[i][j] = tmp;
        }
        col[i] = true;
    }

    candy(0, N, 0);
    cout << answer << endl;
        
    return 0;
}