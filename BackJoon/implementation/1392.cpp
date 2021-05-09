#include <iostream>
#include <map>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int sheetCount, questionCount;
    cin >> sheetCount >> questionCount;

    int timeIndex = 0;
    map<int, int> sheetTable;
    for (int idx = 1; idx <= sheetCount; ++idx) {
        int time;
        cin >> time;

        for (int t = 0; t < time; ++t) {
            sheetTable[timeIndex] = idx;
            timeIndex++;
        }
    }

    for (int idx = 0; idx < questionCount; ++idx) {
        int time;
        cin >> time;
        cout << sheetTable[time] << "\n";
    }

    return 0;
}