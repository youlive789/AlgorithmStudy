#include <iostream>

using namespace std;

bool selectedSeat[30] = {false};
int answer = 0;

bool isSeatValid(int seatIdx) {
    if (seatIdx == 0 && !selectedSeat[seatIdx + 1]) {
        return true;
    }
    else if (seatIdx >= 1 && !selectedSeat[seatIdx + 1] && !selectedSeat[seatIdx - 1]) {
        return true;
    }
    else {
        return false;
    }
}

void seat(int cnt, int peopleIdx, int seatIdx, int numPeople, int numSeat) {
    
    if (peopleIdx >= numPeople) return;
    if (seatIdx >= numSeat) seatIdx = 0;

    if (cnt == numPeople) {
        answer++;
        return;
    }

    // idx번 사람이 seatIdx에 앉을 수 있는지 판단한다.
    bool available = isSeatValid(seatIdx);
    cout << seatIdx << " => " << (available ? "앉을 수 있음" : "못 앉음") << endl;
    cout << cnt << " " << peopleIdx << " " << seatIdx << " " << endl;
    cout << endl;

    if (available) {
        selectedSeat[seatIdx] = true;
        seat(cnt + 1, peopleIdx + 1, seatIdx + 1, numPeople, numSeat);
        selectedSeat[seatIdx] = false;
    }
    
    seat(cnt, peopleIdx, seatIdx + 1, numPeople, numSeat);
    

}

int main() {

    int numSeat, numPeople;
    cin >> numSeat >> numPeople;

    seat(0, 0, 0, numPeople, numSeat);

    cout << answer << endl;

    return 0;
}