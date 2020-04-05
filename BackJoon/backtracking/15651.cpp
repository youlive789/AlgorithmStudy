#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

void comb(vector<int> & target, int number, int count, int maxCount) {
    if (count == maxCount) {
        for (auto num : target) {
            printf("%d ", num);
        }
        printf("\n");
        return;
    }

    for (int idx = 1; idx <= number; idx++) {
        target.push_back(idx);
        comb(target, number, count + 1, maxCount);
        target.pop_back();
    }
}

int main() {

    int N, M;
    cin >> N;
    cin >> M;

    vector<int> target;
    comb(target, N, 0, M);

    return 0;
}