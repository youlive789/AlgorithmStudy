#include <iostream>
#include <stack>
#include <map>

using namespace std;

// 옮길 수 있는지 확인한다.
bool checkDisk(stack<int> &comp1, stack<int> &comp2) {

    bool bothEmpty = comp1.empty() && comp2.empty();

    // 원반에 아무것도 들어있지 않다면
    if (bothEmpty) {
        return false;
    }
    else if (comp1.empty()) {
        return false;
    }
    // 옮길 수 있는 상태라면
    else if (comp2.empty() || comp1.top() < comp2.top()) {
        return true;
    }
    // 그 외의 경우
    else {
        return false;
    }
}

// 디스크를 옮긴다.
void moveDisk(stack<int> &comp1, stack<int> &comp2) {
     comp2.push(comp1.top());
     comp1.pop();
}

void hanoy(map<int, stack<int>> &diskMap, const int& numDisk) {
    // 기저사례:
    // third의 사이즈가 numDisk와 같다면 종료한다.
    if (diskMap[3].size() == numDisk) return;

    // 모든 경우를 전부 시도해보면서 옮겨본다.
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <=3; ++j) {
            if (i==j) continue;
            if (checkDisk(diskMap[i], diskMap[j])) {
                moveDisk(diskMap[i], diskMap[j]);
                cout << "moved : " << i << " " << j << endl;
            }
        }
    }

    hanoy(diskMap, numDisk);
}

int main() {

    int numDisk;
    cin >> numDisk;

    stack<int> first;
    stack<int> second;
    stack<int> third;

    map<int, stack<int>> diskMap;
    diskMap[1] = first;
    diskMap[2] = second;
    diskMap[3] = third;

    // 하노이 탑 초기화
    for (int i = numDisk; i > 0; --i) {
        diskMap[1].push(i);
    }

    hanoy(diskMap, numDisk);

    for (int i = 0; i < third.size(); ++i) {
        cout << third.top() << endl;
        third.pop();
    }

    return 0;
}