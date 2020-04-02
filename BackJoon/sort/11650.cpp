#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int cases;
    cin >> cases;

    vector<pair<int, int>> points;

    while (cases--) {
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        points.push_back(make_pair(x, y));
    }

    // 퀵소트
    sort(points.begin(), points.end());

    for (auto point : points) {
        printf("%d %d\n", point.first, point.second);
    }

    return 0;
}