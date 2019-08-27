#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

void popDisk(stack<int> &origin, stack<int> &target) {
    if (origin.top() < target.top() || target.empty()) {
        int disk = origin.top();
        origin.pop();
        target.push(disk);
    } 
    return;
}

void moveDisk(stack<int> &first, stack<int> &second, stack<int> &third) {
    // first와 second에 디스크가 없으면 종료
    if (first.empty() && second.empty()) return;

    popDisk(first, second);

    //moveDisk(first, second, third);
}

void printDisk(const stack<int> & disks) {
    stack<int> tmp = disks;

    if (tmp.size() <= 0) {
        cout << "Nothing in here." << endl;
    }

    while(!tmp.empty()) {
        cout << tmp.top() << endl;
        tmp.pop();
    }

    return;
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

    cout << "Fisrt disk" << endl;
    printDisk(first);
    cout << endl;

    cout << "Second disk" << endl;
    printDisk(second);
    cout << endl;

    cout << "Third disk" << endl;
    printDisk(third);
    cout << endl;

    return 0;
}