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
    int melodyList[melodyCount];

    for (int index = 0; index < melodyCount; ++index) {
        cin >> melodyList[index];
    }

    for (int index = 1; index < melodyCount; ++index) {
        // 바로 종료조건 - mixed
        if ( (ascCounter > 0 && descCounter > 0) || (ascCounter == 0 && descCounter == 0) ) {
            cout << MIX << endl;
            return 0;
        } 

        if (melodyList[index - 1] - melodyList[index] == -1) {
            ascCounter++;              
        } 
        else if (melodyList[index - 1] - melodyList[index] == 1) {
            descCounter++;     
        }
    }

    if (ascCounter == 7) {
        cout << ASC << endl;
    } 
    else if (descCounter == 7) {
        cout << DESC << endl;
    }

    return 0;
}