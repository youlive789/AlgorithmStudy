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
    if (K.lengthLeft <= 0) return K;

    if (K.steps == 0 || K.lengthLeft == 1) {
        K.lastMove = 1;
    }
    else if (K.lastMove < K.lengthLeft && K.lengthLeft > 2) {
        K.lastMove += 1;
    }
    else if (K.lengthPass > K.lengthLeft && K.lengthLeft > 1) {
        K.lastMove -= 1;
    }

    K.steps += 1;
    K.lengthLeft -= K.lastMove;
    K.lengthPass += K.lastMove;

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