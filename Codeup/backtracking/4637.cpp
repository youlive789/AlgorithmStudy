#include <iostream>
#include <set>

using namespace std;

struct round {
    int win;
    int draw;
    int lose;
};

bool checkAllRounds(int scoreTable[18]) {
    round rounds[6];
    for (int idx = 0; idx < 6; idx++) {
        rounds[idx].win = scoreTable[idx * 3];
        rounds[idx].draw = scoreTable[idx * 3 + 1];
        rounds[idx].lose = scoreTable[idx * 3 + 2];
    }

    for (int idx = 0; idx < 6; idx++) {

        // 승수 체크
    
        // 무승부 체크

        // 패수 체크
    }

    return true;
}

int main() {
    int scoreTable[4][18];
    int cases = 4, casesIdx = 4;
    while (cases--) {
        for (int idx = 0; idx < 18; idx++) {
            int tmp;
            cin >> tmp;
            scoreTable[4 - casesIdx][idx] = tmp;
        }   
        casesIdx--;
    }

    for (int cases = 0; cases < 4; cases++) {
        int totalWin = 0, totalLoses = 0;

        // 승 계산
        for (int idx = 0; idx < 18; idx += 3)
            totalWin += scoreTable[cases][idx];

        // 패 계산
        for (int idx = 2; idx < 18; idx += 3)
            totalLoses += scoreTable[cases][idx];
        
        //cout << "총승 : " << totalWin << " 총패 : " << totalLoses << endl;

        // 승수와 패수가 다르다면 불가능한 결과
        if (totalWin != totalLoses) {
            cout << 0 << " ";
            continue;
        }

        // 무승부는 짝을 이루어야한다.
        int drawScore = 0, drawTrigger = 1;
        for (int idx = 1; idx < 18; idx += 3) {
            drawScore += (scoreTable[cases][idx] * drawTrigger);
            drawTrigger *= -1;
        }

        //cout << "무승부 : " << drawScore << endl;

        // 무승부가 짝을 이루지 않는다면
        if (drawScore != 0) {
            cout << 0 << " ";
            continue;
        }

        // 총 경기수 계산
        set<int> rounds;
        int totalRounds;
        for (int idx = 0; idx < 18; idx += 3) {
            totalRounds = scoreTable[cases][idx] + scoreTable[cases][idx + 1] + scoreTable[cases][idx + 2];
            rounds.insert(totalRounds);
        }

        // 총 경기수가 다르다면
        if (rounds.size() > 1) {
            cout << 0 << " ";
            continue;
        }

        // 모든 국가와 경기했는지 확인
        if (checkAllRounds(scoreTable[cases])) {
            cout << 1 << " ";
        }
        else {
            cout << 0 << " ";
        }
        
    }

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

4 1 0 
3 1 1 
2 1 2 
2 1 2 
0 1 4 
1 1 3
*/