#include <iostream>

using namespace std;

int main() {

    int R, C, A, B;
    cin >> R >> C >> A >> B;

    bool rowTrigger = true;
    for (int i = 0; i < R * A; ++i) {

        if (i % A == 0) {
            rowTrigger = (!rowTrigger);
        }

        bool colTrigger = rowTrigger;
        for (int j = 0; j < C * B; ++j) {
            if (j % B == 0) {
                colTrigger = (!colTrigger);
            }
            
            if (colTrigger) {
                cout << "X";
            }
            else {
                cout << ".";
            }
        }

        cout << "\n";
    }

    return 0;
}