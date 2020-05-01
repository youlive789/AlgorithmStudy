#include <iostream>
#include <vector>

using namespace std;

long long facts[31] = {0};

long long fact(int k) {

    if (facts[k]) {
        return facts[k];
    }
    else {
        if (k == 1) {
            return facts[k] = 1;
        }
        else {
            return facts[k] = k * fact(k - 1);
        }
    }
}

int main() {

    /*
    발상을 전환해서 빈자리를 조합한다고 생각하면 된다.
    그렇다면 factorial도 필요없다.
    */

    int numSeat, numPeople;
    cin >> numSeat >> numPeople;

    int blank = numSeat - numPeople;
    long long answer = fact(blank + 1) / (fact(numPeople) * fact(blank + 1 - numPeople));

    cout << answer << endl;

    return 0;
}