#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int conCount;
    cin >> conCount;

    vector<unsigned long long> conLastDay;
    vector<unsigned long long> conPlan;
    vector<pair<unsigned long long, unsigned long long>> conTable;

    for (int i = 0; i < conCount; i++) {
        unsigned long long int tmp;
        cin >> tmp;
        conLastDay.push_back(tmp);
    }

    for (int i = 0; i < conCount; i++) {
        unsigned long long int tmp;
        cin >> tmp;
        conPlan.push_back(tmp);
    }

    for (int i = 0; i < conCount; i++) {
        conTable.push_back(make_pair(conPlan[i], conLastDay[i]));
    }

    // 남은 사용기간 기준으로 정렬
    sort(conTable.begin(), conTable.end());

    int index = 0;
    unsigned long long answer = 0;
    unsigned long long prevConLastDay = 0, prevConPlan = 0;
    while (index < conTable.size()) {

        cout << "처리 전 " << conTable[index].second << " " << answer << endl;

        // 사용계획일보다 기한이 높도록 설정
        if (conTable[index].second < conTable[index].first) {
            unsigned long long extended = ((conTable[index].first - conTable[index].second) / 30 ) + 1;
            answer += extended;
            conTable[index].second += (30 * extended);
        }

        // 사용계획일 순서에 따른 최대값 설정
        if (conTable[index].second < prevConLastDay) {
            unsigned long long extended = ((prevConLastDay - conTable[index].second) / 30 ) + 1;
            answer += extended;
            prevConLastDay = (30 * extended) + conTable[index].second;
            conTable[index].second += (30 * extended);
        }
        else {
            prevConLastDay = conTable[index].second;
        }

        cout << "처리 후 " << conTable[index].second << " " << answer << endl;

        prevConPlan = conTable[index].first;
        index++;
    }


    cout << answer << endl;

    return 0;
}
/*
3
10 5 4
10 100 30

5
50 40 30 20 10
10 20 30 40 50

4
1 2 2 2
24 2 3 29 
25 30 30 30
6
*/