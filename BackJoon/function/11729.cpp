#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void popDisk(stack<int> &origin, stack<int> &target) {

    int disk = origin.top();
    origin.pop();
    target.push(disk);
    return;
}

void moveDisk(stack<int> &first, stack<int> &second, stack<int> &third) {
    // first와 second에 디스크가 없으면 종료
    if (first.empty() && second.empty()) return;

     moveDisk(first, second, third);
}

int main() {

    stack<int> first;
    stack<int> second;
    stack<int> third;

    int numDisk;
    cin >> numDisk;

    // 하노이탑 초기화
    for (int disk = numDisk; disk >= 1; --disk) {
        first.push(disk);
    }

    moveDisk(first, second, third);

    cout << "done" << endl;
    return 0;
}