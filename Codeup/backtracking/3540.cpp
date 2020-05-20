#include <iostream>
#include <vector>

using namespace std;

vector<char> opers;
char oper[3] = {' ', '+', '-'};

int calculate() {
    for (char op : opers) {
        
    }
}

void makeZero(int idx, int N) {
    if (idx == N) {
        if (calculate() == 0) {
            // print
        }
        return;
    }

    for (char op : oper) {
        opers.push_back(op);
        makeZero(idx+1, N);
        opers.pop_back();
    }
}

int main() {
    return 0;
}