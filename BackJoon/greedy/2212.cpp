#include <iostream>
#include <set>

using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    set<int> container;
    for (int idx = 0; idx < N; idx++) {
        int tmp;
        cin >> tmp;
        container.insert(tmp);
    }

    return 0;
}