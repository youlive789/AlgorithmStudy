#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

void comb(vector<int> target, int lastChoice, int number, int count, int maxCount, bool* used) {
    if (count == maxCount) {
        for (auto num : target) {
            printf("%d ", num);
        }
        printf("\n");
        return;
    }

    for (int idx = lastChoice; idx <= number; idx++) {
         if (!used[idx]) {
            used[idx] = true;
            target.push_back(idx);
            comb(target, idx, number, count + 1, maxCount, used);
            used[idx] = false;
            target.pop_back();
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

    comb(target, 1, N, 0, M, used);
    return 0;
}