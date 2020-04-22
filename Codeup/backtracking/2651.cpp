#include <iostream>
#include <vector>

using namespace std;

int comb(int numPeople, int numSeat) {
    if(numPeople == numSeat || numSeat == 0) {
        return 1;
    }
    
    return comb(numPeople - 1, numSeat - 1) + comb(numPeople - 1, numSeat);
}

int main() {

    int numPeople, numSeat;
    cin >> numPeople >> numSeat;

    int answer = comb(numPeople, numSeat);

    cout << answer << endl;

    return 0;
}