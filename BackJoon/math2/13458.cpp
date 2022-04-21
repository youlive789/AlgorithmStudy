#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {

    int testCase;
    cin >> testCase;

    vector<int> examRooms;
    for (int i = 0; i < testCase; ++i) {
        int examRoomsNumber;
        cin >> examRoomsNumber;
        examRooms.push_back(examRoomsNumber);
    }
    
    int big, small;
    cin >> big >> small;

    long long int answer = 0;
    for (auto examRoomsNumber : examRooms) {
        double temp = examRoomsNumber;

        // 총감독관 계산
        temp -= big;
        answer++;

        // 부감독관 계산
        if (temp > 0) {
            answer += ceil(temp / small);
        }
    }

    cout << answer << endl;

    return 0;
}