#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
평균
메디안
최빈값 -> 여러개라면 두 번째로 작은 최빈값
범위
*/

int main() {

    int cases;
    cin >> cases;
    int counter = cases;
    vector<int> inputs;
    vector<int> countings(8002);

    double mean = 0;
    while (counter--) {
        int temp;
        cin >> temp;
        inputs.push_back(temp);
        countings[temp + 4000]++;
        mean += temp;
    }

    // 정렬
    sort(inputs.begin(), inputs.end());

    // 최빈값 계산
    int mode = max_element(countings.begin(), countings.end()) - countings.begin() - 4000;
    int curMax = *max_element(countings.begin(), countings.end());

    int trigger = 0;
    for (int idx = 0; idx < countings.size(); idx++) {
        if (countings[idx] == curMax) {
            trigger++;
        }
        if (trigger == 2) {
            mode = idx - 4000;
            break;
        }
    }

    mean /= (double)cases;
    mean = round(mean);

    int median = inputs[inputs.size() / 2];
    int range = inputs.back() - inputs.front();

    cout << mean << endl;
    cout << median << endl;
    cout << mode << endl;
    cout << range << endl;

    return 0;
}