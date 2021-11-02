#include <iostream>

using namespace std;

int target[5];

int main() {

    int personPerSquareMeter, area;
    cin >> personPerSquareMeter >> area;

    int totalPerson = personPerSquareMeter * area;
    for (int i = 0; i < 5; ++i) {
        cin >> target[i];
    }

    for (int i = 0; i < 5; ++i) {
        cout << target[i] - totalPerson << " ";
    }

    return 0;
}