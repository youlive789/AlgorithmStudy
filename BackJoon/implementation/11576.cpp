#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

int main() {

    int a, b;
    cin >> a >> b;

    int numPositionCount;
    cin >> numPositionCount;

    unsigned int normalSum = 0;
    for (int i = numPositionCount-1; i >= 0; i--) {
        unsigned int numPosition;
        cin >> numPosition;
        normalSum += pow(a, i) * numPosition;
    }

    stack<unsigned int> numberQ;
    while(true) {
        if (normalSum <= 0) break;
        numberQ.push(normalSum % b);
        normalSum /= b;
    }

    while (!numberQ.empty()) {
        cout << numberQ.top() << " ";
        numberQ.pop();
    }

    return 0;
}