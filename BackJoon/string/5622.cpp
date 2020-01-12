#include <iostream>
#include <string>

using namespace std;

int getTimeSpend(const char& phoneChar) {
    int defaultSpend = 2;
    int phoneCharCasting = static_cast<int>(phoneChar);

    if (phoneCharCasting >= 87) {
        return defaultSpend + 8;
    }
    else if (phoneCharCasting >= 84 && phoneCharCasting < 87) {
        return defaultSpend + 7;
    }
    else if (phoneCharCasting >= 80 && phoneCharCasting < 84) {
        return defaultSpend + 6;
    }
    else if (phoneCharCasting >= 77 && phoneCharCasting < 80) {
        return defaultSpend + 5;
    }
    else if (phoneCharCasting >= 74 && phoneCharCasting < 77) {
        return defaultSpend + 4;
    }
    else if (phoneCharCasting >= 71 && phoneCharCasting < 74) {
        return defaultSpend + 3;
    }
    else if (phoneCharCasting >= 68 && phoneCharCasting < 71) {
        return defaultSpend + 2;
    }
    else if (phoneCharCasting >= 65 && phoneCharCasting < 68) {
        return defaultSpend + 1;
    }
}

int main() {

    string inputPhoneNumber;
    cin >> inputPhoneNumber;
    
    int totalSpendTime = 0;
    for (int index = 0; index < inputPhoneNumber.size(); index++) {
        totalSpendTime += getTimeSpend(inputPhoneNumber[index]);
    }

    cout << totalSpendTime << endl;

    return 0;
}