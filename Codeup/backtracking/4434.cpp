#include <iostream>
#include <string>

using namespace std;

string numbers[3] = {"1", "2", "3"};

bool checkSeries(const string& series) {

    bool result = true;
    int sizeIdx = 2;
    int firstIdx = 0;
    int seriesSize = series.size();

    if (seriesSize <= 2) return result;

    while (firstIdx <= seriesSize - 2) {

        string subset = series.substr(firstIdx, sizeIdx);
        string lastPart = series.substr(firstIdx + sizeIdx, -1);

        if (subset.size() > lastPart.size()) {
            sizeIdx = 1;
            firstIdx++;
            continue;
        }

        if (lastPart.find(subset) == 0) {
            result = false;
            break;
        }

        sizeIdx++;
        
        if (firstIdx + sizeIdx == seriesSize - 1) {
            sizeIdx = 1;
            firstIdx++;
        }
    }

    return result;
}

void makeNumbers(int N, string series, int lastChoose) {
    // 기저사례 : 수열을 다 만들었다면
    if (!checkSeries(series)) return;
    if (series.size() == N) {
        cout << series << endl;
        exit(0);
    }

    // 세 개의 숫자 중 하나 뽑기
    for (int idx = 0; idx < 3; idx++) {
        if (idx != lastChoose) {
            series.append(numbers[idx]);
            makeNumbers(N, series, idx);
            series = series.substr(0, series.size() - 1);
        }
    }
    
}

int main() {

    int N;
    cin >> N;

    string series = "";
    makeNumbers(N, series, -1);

    return 0;
}