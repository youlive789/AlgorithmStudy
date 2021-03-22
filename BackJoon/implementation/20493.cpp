#include <iostream>
#include <string>

using namespace std;

int main() {

    int x = 0, y = 0;
    int changeCount, totalTime;
    cin >> changeCount >> totalTime;

    int xDirection[] = {1, 0, -1, 0};
    int yDirection[] = {0, -1, 0, 1};
    int lastTime = 0, directionIndex = 0, diff = 0;

    if (changeCount > 0) {
        while (changeCount > 0) {
            int nowTime;
            string direction;
            cin >> nowTime >> direction;

            diff = nowTime - lastTime;
            x += diff * xDirection[directionIndex];
            y += diff * yDirection[directionIndex];
            
            if (direction == "right") {
                directionIndex++;
            }
            else {
                directionIndex--;
            }

            if (directionIndex > 3) {
                directionIndex = 0;
            }
            else if (directionIndex < 0) {
                directionIndex = 3;
            }

            changeCount--;
            lastTime = nowTime;
        }

        diff = totalTime - lastTime;
        x += diff * xDirection[directionIndex];
        y += diff * yDirection[directionIndex];

    }
    else {
        x += totalTime;
    }

    cout << x << " " << y << endl;

    return 0;
}