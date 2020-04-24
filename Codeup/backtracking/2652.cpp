#include <iostream>

using namespace std;

int answer = 0;
bool grid[30] = {false};

bool valid(int seatIdx, int numSeat) {
    if (seatIdx == 0 && !grid[seatIdx + 1]) return true;
    if (seatIdx >= 1 && !grid[seatIdx - 1] && !grid[seatIdx + 1]) {
        return true;
    }
    else {
        return false;
    }
}

void seat(int peopleIdx, int seatIdx, int numPeople, int numSeat) {

    if (seatIdx + 1 == numSeat - 1) {
        if (valid(seatIdx + 1, numSeat)) {
            answer++;
            return;
        }
    }

    if (seatIdx == numSeat - 1) {
        if (valid(seatIdx, numSeat)) {
            answer++;
            return;
        }
    }

    if (valid(seatIdx, numSeat)) {
        grid[seatIdx] = true;
        seat(peopleIdx+1, seatIdx+1, numPeople, numSeat);
        grid[seatIdx] = false;
    }
    else {
        seat(peopleIdx, seatIdx+1, numPeople, numSeat);
    }
}

int main() {

    int numSeat, numPeople;
    cin >> numSeat >> numPeople;

    seat(0, 0, numPeople, numSeat);

    cout << answer << endl;

    return 0;
}