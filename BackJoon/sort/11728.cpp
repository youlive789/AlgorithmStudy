#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {

    int aSize, bSize;
    cin >> aSize >> bSize;

    vector<int> container;
    
    for (int idx = 0; idx < aSize; idx++) {
        int temp;
        scanf("%d", &temp);
        container.push_back(temp);
    }

    for (int idx = 0; idx < bSize; idx++) {
        int temp;
        scanf("%d", &temp);
        container.push_back(temp);
    }

    sort(container.begin(), container.end());

    for (int idx = 0; idx < container.size(); idx++) {
        printf("%d ", container.at(idx));
    }

    return 0;
}