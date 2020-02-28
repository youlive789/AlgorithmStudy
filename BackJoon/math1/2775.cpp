#include <iostream>

using namespace std;

int main() {

    int cases;
    cin >> cases;

    while(cases--) {
        int floor, room;
        cin >> floor;
        cin >> room;

        int roomList[15];
        for (int index = 1; index <= 14; index++) {
            roomList[index] = index;
        }

        for (int f = 1; f <= floor; f++) {
            for (int r = 2; r <= room; r++) {
                roomList[r] = roomList[r] + roomList[r-1];
            }
        }

        cout << roomList[room] << endl;
    }

    return 0;
}