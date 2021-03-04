#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> container;

    int index = 1;
    while (container.size() < 1000) {
        for (int i = 0; i < index; ++i) {
            container.push_back(index);
        }
        index++;
    }

    int answer = 0;
    int start, end;
    cin >> start >> end;

    for (int i = start-1; i <= end-1; ++i) {
        answer += container.at(i);
    }

    cout << answer << endl;

    return 0;
}