#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    vector<int> container;
    for (int idx = 0; idx < N; idx++) {
        int tmp;
        cin >> tmp;
        container.push_back(tmp);
    }

    return 0;
}