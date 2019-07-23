#include <iostream>
#include <string>

using namespace std;

int main() {

    int numberCase = 0;
    cin >> numberCase;

    string testCase;
    int sizeTestCase = 0;

    int sumPoint[numberCase] = {0};
    int currentPoint = 0;

    for (int index = 0; index < numberCase; ++index) {
        
        cin >> testCase;
        sizeTestCase = testCase.size();
        
        for (int stringIndex = 0; stringIndex < sizeTestCase; ++stringIndex) {
            if (testCase[stringIndex] == 'O') {
                ++currentPoint;
            }
            else {
                currentPoint = 0;
            }
            sumPoint[index] += currentPoint;        
        }    
        currentPoint = 0;          
    }

    for (int index = 0; index < numberCase; ++index) {
        cout << sumPoint[index] << endl;
    }

    return 0;
}