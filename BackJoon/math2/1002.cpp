#include <iostream>
#include <cmath>

using namespace std;

int main() {

    /*
    두 원의 교점 개수 구하기
    (x - x1)^2 + (y - y1)^2 = r1^2
    (x - x2)^2 + (y - y2)^2 = r2^2

    두 원의 중심까지의 거리가 r1, r2의 합보다
    크다면 : 0
    같다면 : 1
    작다면 : 2
    */

    int cases;
    cin >> cases;
    while (cases--) {
        double x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int radiusSum = r1 + r2;
        int radiusDiff = abs(r1 - r2);
        double centralLength = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

        if (centralLength == 0 && radiusDiff == 0) {
            cout << -1 << endl;
        }
        else if (centralLength > radiusDiff && centralLength < radiusSum) {
            cout << 2 << endl;
        }
        else if (centralLength < radiusDiff || centralLength > radiusSum) {
            cout << 0 << endl;
        }
        else if (centralLength == radiusSum || centralLength == radiusDiff) {
            cout << 1 << endl;
        }
        
    }

    return 0;
}