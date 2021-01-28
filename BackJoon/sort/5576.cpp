#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {

    vector<int> w;
    vector<int> k;

    for (int i = 0; i < 10; i++) {
        int temp;
        cin >> temp;
        w.push_back(temp);
    }

    for (int i = 0; i < 10; i++) {
        int temp;
        cin >> temp;
        k.push_back(temp);
    }

    sort(w.begin(), w.end(), greater<>());
    sort(k.begin(), k.end(), greater<>());

    int wSum = w.at(0) + w.at(1) + w.at(2);
    int kSum = k.at(0) + k.at(1) + k.at(2);

    cout << wSum << " " << kSum << endl;

    return 0;
}