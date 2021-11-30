#include <iostream>

using namespace std;

int stores[1000];

int getNextStore(const int& currentStore) {
    switch (currentStore)
    {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 0;
    default:
        return 0;
    }
}

int main() {
    
    int storeNum;
    cin >> storeNum;

    for (int i = 0; i < storeNum; ++i) {
        cin >> stores[i];
    }

    int answer = 0;
    int currentStore = -1;
    for (int i = 0; i < storeNum - 1; ++i) {
        if (currentStore == -1) {
            if (stores[i] != 0) {
                continue;
            }
            else {
                currentStore = 0;
                answer++;
            }
        }

        if (getNextStore(currentStore) == stores[i+1]) {
            answer++;
            currentStore = stores[i+1];
        }
    }

    cout << answer << endl;

    return 0;
}