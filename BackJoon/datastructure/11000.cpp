#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int count;
    cin >> count;

    vector<pair<int, int>> timeTable;

    for (int idx = 0; idx < count; idx++) {
        int startTime, endTime;
        cin >> startTime >> endTime;
        timeTable.push_back(make_pair(startTime, endTime));
    }

    sort(timeTable.begin(), timeTable.end(), [] (pair<int, int> a, pair<int, int> b) {
        if (a.second <= b.second) {
            return true;
        }
        else if (a.first <= b.first) {
            return true;
        }
        else {
            return false;
        }
    });

    for (int idx = 0; idx < count; idx++) {
        
    }

    return 0;
}