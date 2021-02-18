#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int *cards = new int[21];
    for (int val = 1; val < 21; val++) {
        cards[val] = val;
    }

    for (int i = 0; i < 10; i++) {
        int start, end;
        cin >> start >> end;

        int midPoint;
        midPoint = (end - start) / 2;

        for (int idx = 0; idx <= midPoint; idx++) {
            int tmp;
            tmp = cards[start+idx];
            cards[start+idx] = cards[end-idx];
            cards[end-idx] = tmp;
        }
    }

    for (int i = 1; i < 21; i++) {
        cout << cards[i] << " ";
    }
    cout << endl;
    delete[] cards;

    return 0;
}