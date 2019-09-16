#include <iostream>
#include <stack>

using namespace std;

// 옮길 수 있는지 확인한다.
bool checkDisk(stack<int> &comp1, stack<int> &comp2) {
    if (comp2.empty() || comp1.top() < comp2.top()) {
        return true;
    } else {
        return false;
    }
}

// 디스크를 옮긴다.
void moveDisk(stack<int> &comp1, stack<int> &comp2) {
     comp2.push(comp1.top());
     comp1.pop();
}

void hanoy(stack<int> &first, stack<int> &second, stack<int> &third, const int& numDisk) {
    // 기저사례:
    // third의 사이즈가 numDisk와 같다면 종료한다.
    if (third.size() == numDisk) return;

    // 처음 옮길 때 3번으로 시도한다.
    // 3번이 차있다면 2번으로 시도한다.
    // 모두 차있다면 3번에서 2번으로, 2번에서 1번으로 시도한다.

    hanoy(first, second, third, numDisk);
}

int main() {

    int numDisk;
    cin >> numDisk;

    stack<int> first;
    stack<int> second;
    stack<int> third;

    // 하노이 탑 초기화
    for (int i = numDisk; i > 0; --i) {
        first.push(i);
    }

    cout << "before hanoy" << endl;
    hanoy(first, second, third, numDisk);
    cout << "end hanoy" << endl;

    for (int i = 0; i < third.size(); ++i) {
        cout << third.top() << endl;
        third.pop();
    }

    return 0;
}