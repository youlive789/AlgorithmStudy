#include <iostream>
#include <set>

using namespace std;

struct round {
    int win;
    int draw;
    int lose;
};

bool result[4];

void cntRounds(int cases, round rounds[6], int nowIdx) {

    if (nowIdx == 6) {
        for (int i = 0; i < 6; i++) {
            if (rounds[i].win != 0 || rounds[i].draw != 0 || rounds[i].lose != 0) break;
        }
        result[cases] = true;
        return;
    }

    if (cases == 2) {
        cout << "경기 인덱스 " << cases << " ==> ";
        for (int i = 0; i < 6; i++) {
            cout << rounds[i].win << " ";
            cout << rounds[i].draw << " ";
            cout << rounds[i].lose << " ";
        }
        cout << endl;
    }

    // 모든 국가끼리 경기를 수행해본다.
    for (int idx = nowIdx; idx < 5; idx++) {
        // 승
        if (rounds[idx].win > 0 && rounds[idx+1].lose > 0) {
            rounds[idx].win--;
            rounds[idx+1].lose--;
            cntRounds(cases, rounds, idx+1);
            rounds[idx].win++;
            rounds[idx+1].lose++;
        }

        // 무승부
        if (rounds[idx].draw > 0 && rounds[idx+1].draw > 0) {
            rounds[idx].draw--;
            rounds[idx+1].draw--;
            cntRounds(cases, rounds, idx+1);
            rounds[idx].draw++;
            rounds[idx+1].draw++;
        }

        // 패
        if (rounds[idx].lose > 0 && rounds[idx+1].win > 0) {
            rounds[idx].lose--;
            rounds[idx+1].win--;
            cntRounds(cases, rounds, idx+1);
            rounds[idx].lose++;
            rounds[idx+1].win++;
        }
    }
}

int main() {

    round rounds[4][6];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 18; j++) {
            int tmp;
            cin >> tmp;

            if (j % 3 == 0) rounds[i][j / 3].win = tmp;
            if (j % 3 == 1) rounds[i][j / 3].draw = tmp;
            if (j % 3 == 2) rounds[i][j / 3].lose = tmp;
        }
    }

    for (int i = 0; i < 4; i++)
        cntRounds(i, rounds[i], 0);

    for (int i = 0; i < 4; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}

/*
4 0 0 4 0 1 3 0 2 2 0 3 1 0 4 0 0 4
5 0 0 0 5 0 0 0 5 5 0 0 0 5 0 0 0 5
2 3 0 0 0 5 2 3 0 2 3 0 1 0 4 2 3 0
4 1 0 3 1 1 2 1 2 2 1 2 0 1 4 1 1 3
=> 0 0 1 1

0 5 0 0 5 0 0 5 0 0 5 0 0 5 0 0 5 0
1 4 0 1 4 0 0 4 1 0 4 1 3 0 2 2 0 3
5 0 0 0 0 5 4 0 1 1 0 4 5 0 0 0 0 5
1 3 1 1 3 1 4 0 1 1 0 4 4 0 1 1 0 4
=> 1 0 0 0
*/