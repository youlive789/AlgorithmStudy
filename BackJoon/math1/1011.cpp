#include <iostream>
#include <cmath>

using namespace std;

struct Step {
    int steps;
    int lengthPass;
    int lengthLeft;
    int lastMove;
};

// Bruteforce
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

int getOptimalStep(const int& length) {
    if (length <= 3) return length;
    if (length % 2 == 0) {
        return -2 + ceil(sqrt(1 + 4 * length));
    }
    else {
        return -2 + ceil(sqrt(2 + 4* length));
    }
}

int main() {

    int cases;
    cin >> cases;

    while (cases--) {
        int x, y;
        cin >> x >> y;
        cout << getOptimalStep(y - x) << endl;
    }

    return 0;
}

/*
1 1
2 2
3 3

4 6     sum(n/2) * 2 = L
5 9     sum(n/2) * 2 + ceil(n/2) = L
6 12    
7 16    
8 20    
9 25    

L / 2 = sum(n/2) = (n/2) * (n/2 + 1) / 2
L = n/2 * (n/2 + 1)
2L = n^2 + 2n
*/