#include <iostream>
#include <string>

using namespace std;

string numbers[3] = {"1", "2", "3"};

bool checkSeries(string series) {
    return true;
}

void makeNumbers(int N, string series, int lastChoose) {
    // 기저사례 : 수열을 다 만들었다면
    if (series.size() == N) {
        cout << series << endl;
        return;
    }

    // 나쁜 수열인지 확인하기
    if (checkSeries(series)) {
        // 세 개의 숫자 중 하나 뽑기
        for (int idx = 0; idx < 3; idx++) {
            if (idx != lastChoose) {
                series.append(numbers[idx]);
                makeNumbers(N, series, idx);
                series = series.substr(series.size() - 1);
            }
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