#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // 직사각형의 경계선
    // w - x, h - y 중 큰 값을 리턴한다.
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int xLength = w - x;
    int yLength = h - y;

    vector<int> length;
    length.push_back(x);
    length.push_back(y);
    length.push_back(xLength);
    length.push_back(yLength);

    int min = *min_element(length.begin(), length.end());
    cout << min << endl;

    return 0;
}