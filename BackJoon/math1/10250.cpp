#include <iostream>

using namespace std;

int main() {

    // H: 층수, W: 방수, N: N번째 손님
    // 6 12 10 - 402
    // 30 50 72 - 1203
    int cases, cntFloor, cntRoom, customer;
    cin >> cases >> cntFloor >> cntRoom >> customer;

    int index = 0;
    int roomNumber = 0, floorNumber = 0;
    for (int room = 1; room <= cntRoom; room++) {
        for (int floor = 1; floor <= cntFloor; floor++) {
            index++;
            if (customer == index) {
                roomNumber = room;
                floorNumber = floor;
            }
        }
    }
    
    cout << floorNumber << roomNumber << endl;

    return 0;
}