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

    int num = 1;
    while (true) {
        long totalCost = fixedCost + (productCost * num);
        long income = price * num;

        if (income > totalCost) {
            break;
        }
        num++;
    }

    cout << num << endl;

    return 0;
}