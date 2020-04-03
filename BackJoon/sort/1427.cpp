#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    unsigned long long nums;
    cin >> nums;
    vector<int> arr;

    while (nums) {
        arr.push_back(nums % 10);
        nums /= 10;
    }

    sort(arr.begin(), arr.end());

    for (int idx = arr.size() - 1; idx >= 0; idx--) {
        printf("%d", arr[idx]);
    }
}