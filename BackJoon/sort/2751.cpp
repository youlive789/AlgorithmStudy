#include <cstdio>
#include <vector>

using namespace std;

void mergesort(vector<int> & target);
void partition(vector<int> & target, int start, int end);
void merge(vector<int> & target, int start, int half, int end);

int main() {

    int cases;
    scanf("%d", &cases);
    vector<int> testArr;
    while (cases--) {
        int temp;
        scanf("%d", &temp);
        testArr.push_back(temp);
    }
    
    mergesort(testArr);

    for (int idx = 0; idx < testArr.size(); idx++) {
        printf("%d\n", testArr[idx]);
    }

    return 0;
}

void mergesort(vector<int> & target) {
    partition(target, 0, target.size() - 1);
}

void partition(vector<int> & target, int start, int end) {
    if (start < end) {
        int half = (start + end) / 2;
        partition(target, start, half);
        partition(target, half+1, end);
        merge(target, start, half, end);
    }
}

void merge(vector<int> & target, int start, int half, int end) {
    int part1 = start;
    int part2 = half + 1;
    int index = start;

    int temp[target.size()];

    while (part1 <= half && part2 <= end) {
        if (target[part1] < target[part2]) {
            temp[index] = target[part1];
            part1++;
        }
        else {
            temp[index] = target[part2];
            part2++;
        }
        index++;
    }

    if (part1 > half) {
        for (int idx = part2; idx <= end; idx++) {
            temp[index] = target[idx];
            index++;
        }
    }
    else {
        for (int idx = part1; idx <= half; idx++) {
            temp[index] = target[idx];
            index++;
        }
    }

    for (int idx = start; idx <= end; idx++) {
        target[idx] = temp[idx];
    }

}