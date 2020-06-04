#include <iostream>
#include <vector>

using namespace std;

struct country {
    int win;
    int draw;
    int lose;
};

bool result[4];

void cntRounds(int cases, country countries[6], int nowIdx) {

    // if (cases == 0) {
    //     cout << nowIdx << " ";
    //     for (int i = 0; i < 6; i ++) {
    //         cout << countries[i].win << " " << countries[i].draw << " " << countries[i].lose << " ";
    //     }
    //     cout << endl;
    // }

    if (nowIdx == 6) {
        for (int i = 0; i < 6; i ++) {
            if (countries[i].win != 0 || countries[i].draw != 0 || countries[i].lose != 0) return;
        }

        result[cases] = true;
    }

    // 모든 국가끼리 경기를 수행해본다.

    for (int idx = nowIdx; idx <= 6; idx++) {
        for (int i = 0; i < 6; ++i) {
            
            if (i == idx) continue;
            //if (cases == 0) cout << idx << " " << i << endl;
            
            // 승
            if (countries[idx].win > 0 && countries[i].lose > 0) {
                countries[idx].win--;
                countries[i].lose--;
                cntRounds(cases, countries, idx);
                countries[idx].win++;
                countries[i].lose++;
            }

            // 무승부
            if (countries[idx].draw > 0 && countries[i].draw > 0) {
                countries[idx].draw--;
                countries[i].draw--;
                cntRounds(cases, countries, idx);
                countries[idx].draw++;
                countries[i].draw++;
            }

            // 패
            if (countries[nowIdx].lose > 0 && countries[i].win > 0) {
                countries[nowIdx].lose++;
                countries[i].win--;
                cntRounds(cases, countries, nowIdx);
                countries[nowIdx].lose--;
                countries[i].win++;
            }
        }
    }
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


int main() {

    country countries[4][6];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 18; j++) {
            int tmp;
            cin >> tmp;

            if (j % 3 == 0) countries[i][j / 3].win = tmp;
            if (j % 3 == 1) countries[i][j / 3].draw = tmp;
            if (j % 3 == 2) countries[i][j / 3].lose = tmp;
        }
    }

    for (int i = 0; i < 4; i++)
        cntRounds(i, countries[i], 0);

    for (int i = 0; i < 4; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
