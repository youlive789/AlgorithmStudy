#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    while (true) {

        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;
        sort(arr, arr + 3);

        if (arr[2] * arr[2] == arr[1] * arr[1] + arr[0] * arr[0]) {
            cout << "right" << endl;
        }
        else { 
            cout << "wrong" << endl;
        }
    }

    return 0;
}