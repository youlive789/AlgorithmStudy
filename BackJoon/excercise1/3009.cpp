#include <iostream>
#include <map>

using namespace std;

int main() {

    map<int, int> xCordMap;
    map<int, int> yCordMap;

    int cases = 3;
    int xAnswer, yAnswer;
    while (cases--) {
        int x, y;
        cin >> x >> y;

        if (xCordMap.find(x) == xCordMap.end()) {
            xCordMap.insert(make_pair(x, 1));
        }
        else {
            xCordMap[x] += 1;
        }

        if (yCordMap.find(y) == yCordMap.end()) {
            yCordMap.insert(make_pair(y, 1));
        }
        else {
            yCordMap[y] += 1;
        }
    }

    for (auto xPair : xCordMap) {
        if (xPair.second == 1) {
            xAnswer = xPair.first;
        }
    }

    for (auto yPair : yCordMap) {
        if (yPair.second == 1) {
            yAnswer = yPair.first;
        }
    }

    cout << xAnswer << " " << yAnswer << endl;

    return 0;
}