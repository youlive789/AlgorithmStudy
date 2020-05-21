#include <iostream>
#include <queue>

using namespace std;

vector<char> opers;
char oper[3] = {'+', '-', ' '};

int calculate(int N) {
    // queue를 이용해서 구현하자!
    return 0;
}

void makeZero(int idx, int cntOper, int N) {
    if (idx == cntOper) {
        if (calculate(N) == 0) {
            for (int i = 0; i < opers.size(); i++) {
                cout << (i+1) << " ";
                cout << opers[i] << " ";
            }
            cout << N << endl;
        }
        return;
    }

    for (char op : oper) {
        opers.push_back(op);
        makeZero(idx+1, cntOper, N);
        opers.pop_back();
    }
}

int main() {
    int N;
    cin >> N;
    makeZero(0, N-1, N);
    return 0;
}