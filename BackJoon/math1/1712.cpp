#include <iostream>

using namespace std;

int main() {

    long fixedCost;
    cin >> fixedCost;

    long productCost;
    cin >> productCost;

    long price;
    cin >> price;

    if (price <= productCost) {
        cout << -1 << endl;
        return 0;
    } 

    long answer = (fixedCost / (price - productCost)) + 1;
    cout << answer << endl;

    return 0;
}