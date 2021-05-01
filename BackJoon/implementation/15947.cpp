#include <iostream>
#include <string>

using namespace std;

int main() {

    string song[14] = {"baby", "sukhwan", "tururu", "turu", 
    "very", "cute", "tururu", "turu", "in", "bed", "tururu", "turu", "baby", "sukhwan"};

    // 3, 7, 11
    // 4, 8, 12

    int number;
    cin >> number;

    int repeatCount = (number / 14);
    int wordPosition = (number % 14 == 0 ? 14 : number % 14) - 1;

    if (wordPosition == 2 || wordPosition == 6 || wordPosition == 10) {
        if (repeatCount < 3) {
            string ru = "";
            for (int i = 0; i < repeatCount; ++i) {
                ru += "ru";
            }
            cout << song[wordPosition] + ru << endl;
        }
        else {
            cout << "tu+ru*" << repeatCount + 2 << endl;
        }
    }
    else if (wordPosition == 3 || wordPosition == 7 || wordPosition == 11) {
        if (repeatCount < 4) {
            string ru = "";
            for (int i = 0; i < repeatCount; ++i) {
                ru += "ru";
            }
            cout << song[wordPosition] + ru << endl;
        }
        else {
            cout << "tu+ru*" << repeatCount + 1 << endl;
        }
    }
    else {
        cout << song[wordPosition] << endl;
    }

    return 0;
}