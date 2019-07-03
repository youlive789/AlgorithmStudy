#include <iostream>
#include <string>

using namespace std;

int main() {

    const string ASC = "ascending";
    const string DESC = "descending";
    const string MIX = "mixed";
    
    int ascCounter = 0;
    int descCounter = 0;
    int melodyCount = 8;

    for (int index = 0; index < melodyCount; ++index) {
        // 바로 종료조건 - mixed
        if (ascCounter > 0 && descCounter > 0) {
            cout << MIX << endl;
            break;
        }
    }

    return 0;
}