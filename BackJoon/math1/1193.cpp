#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int inputNumber;
    cin >> inputNumber;

    int layer = static_cast<int>(ceil( (-1 + sqrt(1 + 8 * inputNumber)) / 2 ));
    int layerCnt = layer * (layer + 1) / 2;
    int numberIndex = layerCnt - inputNumber;

    int x, y = -999;
    bool layerEven = ((layer % 2) == 0);

    if (layerEven) {
        x = 1;
        y = layer;
        while (numberIndex != 0) {
            x++;
            y--;
            numberIndex--;
        }
    }
    else {
        x = layer;
        y = 1;
        while (numberIndex != 0) {
            x--;
            y++;
            numberIndex--;
        }
    }
    
    cout << x << "/" << y << endl;

    return 0;
}