#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int nums[4];

    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        cin >> nums[i];
    }

    sort(nums, nums+4);

    for (int i = 3; i > 0; --i) {
        sum += nums[i];
    }

    int a, b;
    cin >> a >> b;

    sum = a > b ? sum + a : sum + b;
    cout << sum << endl;

    return 0;
}