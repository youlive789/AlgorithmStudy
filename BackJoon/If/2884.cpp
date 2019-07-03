#include <iostream>
#include <math.h>

using namespace std;

int main() {

    int hour;
    int minute;

    cin >> hour;
    cin >> minute;

    minute -= 45;
    if (minute < 0) {
        minute += 60;
        hour--;
    }

    if (hour < 0) {
        hour += 24;
    } 
    else if (hour > 24) {
        hour -= 24;
    }

    cout << hour << " " << minute;

    return 0;
}