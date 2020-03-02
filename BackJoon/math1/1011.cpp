#include <iostream>
#include <cmath>

using namespace std;

struct Step {
    int steps;
    int lengthPass;
    int lengthLeft;
    int lastMove;
};

Step moveStep(Step K) {
    // 종료조건: lengthLeft == 0
    if (K.lengthLeft <= 0) return K;

    // 처음과 마지막에는 1밖에 못움직인다.
    if (K.steps == 0 || K.lengthLeft == 1) {
        K.steps += 1;
        K.lastMove = 1;
        K.lengthLeft -= 1;
        K.lengthPass += 1;
    }
    else if (K.lastMove < sqrt(K.lengthLeft)){
        K.steps += 1;
        K.lastMove += 1;
        K.lengthLeft -= K.lastMove;
        K.lengthPass += K.lastMove;
    }
    else if (K.lengthPass > K.lengthLeft && K.lengthLeft > 1) {
        K.steps += 1;
        K.lastMove -= 1;
        K.lengthLeft -= K.lastMove;
        K.lengthPass += K.lastMove;
    }
    else {
        K.steps += 1;
        K.lengthLeft -= K.lastMove;
        K.lengthPass += K.lastMove;
    }

    cout << K.steps << K.lengthPass << K.lastMove << endl;

    moveStep(K);
}

int main() {

    int cases;
    cin >> cases;

    while (cases--) {
        int x, y;
        cin >> x >> y;

        Step K;
        K.steps = 0;
        K.lengthPass = 0;
        K.lengthLeft = y - x;
        K.lastMove = 0;
        
        K = moveStep(K);
        cout << K.steps << endl;
    }

    return 0;
}