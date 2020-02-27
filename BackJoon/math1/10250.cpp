#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // H: 층수, W: 방수, N: N번째 손님
    // 6 12 10 - 402
    // 30 50 72 - 1203
    int cases;
    cin >> cases;

    while (cases--) {
        int cntFloor, cntRoom, customer;
        cin >> cntFloor >> cntRoom >> customer;

        int floor = customer % cntFloor;
        int floorTrigger = 1;
        if (floor == 0) {
            floor = cntFloor;
            floorTrigger = 0;
        }

        int room = customer / cntFloor + floorTrigger;

        cout << floor << setfill('0') << setw(2) << room << endl;
    }
    return 0;
}