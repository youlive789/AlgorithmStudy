#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void comb(vector<int> & target, bool* used, int number, int count, int maxCount) {
    if (count == maxCount) {
        for (auto num : target) {
            printf("%d ", num);
        }
        printf("\n");
        return;
    }

    for (int idx = 1; idx <= number; idx++) {
        if (!used[idx + 1]) {
            target.push_back(idx);
            used[idx+1] = true;
            comb(target, used, number, count + 1, maxCount);
            target.pop_back();
            used[idx+1] = false;
        }
    }
}

int main() {

    int N, M;
    cin >> N;
    cin >> M;

    vector<int> target;
    bool* used = new bool[N + 1];
    memset(used, false, sizeof(bool) * N);

    comb(target, used, N, 0, M);

    return 0;
}