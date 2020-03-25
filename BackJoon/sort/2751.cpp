#include <iostream>
#include <vector>

using namespace std;

void mergesort(int target[], int size);
void partition(int target[], int temp[], int start, int end);
void merge(int target[], int temp[], int start, int half, int end);

int main() {

    int testArr[] = {5, 7, 3 , 2, 1, 9, 8, 4};
    int size = sizeof(testArr)/sizeof(int);

    mergesort(testArr, size);

    for (int idx = 0; idx < size; idx++) {
        cout << testArr[idx] << " ";
    }


    return 0;
}

void mergesort(int target[], int size) {
    int temp[size];
    partition(target, temp, 0, size - 1);
}

void partition(int target[], int temp[], int start, int end) {
    if (start < end) {
        int half = (start + end) / 2;
        partition(target, temp, start, half);
        partition(target, temp, half+1, end);
        merge(target, temp, start, half, end);
    }
}

void merge(int target[], int temp[], int start, int half, int end) {
    int part1 = start;
    int part2 = half + 1;
    int index = start;

    for (int idx = start; idx < end; idx++) {
        temp[idx] = target[idx];
    }

    while (part1 <= half && part2 <= end) {
        if (temp[part1] <= temp[part2]) {
            target[index] = temp[part1];
            part1++;
        }
        else {
            target[index] = temp[part2];
            part2++;
        }
        index++;
    }

    for (int idx = 0; idx <= half - part1; idx++) {
        target[idx + 1] = temp[part1 + idx];
    }
}