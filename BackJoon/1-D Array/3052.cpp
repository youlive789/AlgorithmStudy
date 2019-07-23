#include <iostream>
#include <set>

using namespace std;

int main() {
    
    int inputNumber;
    set<int> remainders;

    for (int index = 0; index < 10; ++index) {
        cin >> inputNumber;
        remainders.insert(inputNumber % 42);
    }       
    cout << remainders.size() << endl;

    return 0;
}