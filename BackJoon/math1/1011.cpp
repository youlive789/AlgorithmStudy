#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int cases; 
    cin >> cases;

    while (cases--) {
        int x, y;
        cin >> x >> y;

        long length = y - x;
        long answer = 1;
        long dis = 0;

        while(length > dis) {
            answer++;
            dis += answer / 2;
        }
        cout << answer - 1 << endl;
    }

    return 0;
}