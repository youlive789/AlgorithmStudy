#include <iostream>
#include <vector>

using namespace std;

void comb(vector<int> target, int lastChoice, int number, int count, int maxCount) {
    if (count == maxCount) {
        for (auto num : target) {
            printf("%d ", num);
        }
        printf("\n");
        return;
    }

    for (int idx = lastChoice; idx <= number; idx++) {
        target.push_back(idx);
        comb(target, idx, number, count + 1, maxCount);
        target.pop_back();
    }
}

int main() {

    int N, M;
    cin >> N;
    cin >> M;

    vector<int> target;
    comb(target, 1, N, 0, M);

    return 0;
}