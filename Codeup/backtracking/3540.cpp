#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<char> opers;
char oper[3] = {' ', '+', '-'};

int calculate(int N) {
    vector<int> tmp;
    vector<int> eraseIdx;
    deque<int> numbers;

    // 임시 숫자 배열생성
    for (int i = 1; i <= N; i++) {
        tmp.push_back(i);
    }   
    
    // 공백연산 처리
    int numIdx = 0;
    for (int i = 0; i < opers.size(); i++) {
        if (opers[i] == ' ') {
            tmp[numIdx] = tmp[numIdx] * 10 + tmp[numIdx+1];
            tmp.erase(tmp.begin() + (numIdx + 1));
        }
        else {
            numIdx++;
        }
    }

    // 실제 계산할 숫자 삽입
    for (int num : tmp) {
        numbers.push_back(num);
    }
    
    // 연산 수행
    for (char op : opers) {
        if (op == ' ') {
            continue;
        }
        else if (op == '+') {
            int a = numbers.front();
            numbers.pop_front();

            int b = numbers.front();
            numbers.pop_front();

            int num = a + b;
            numbers.push_front(num);
        }
        else if (op == '-') {
            int a = numbers.front();
            numbers.pop_front();

            int b = numbers.front();
            numbers.pop_front();

            int num = a - b;
            numbers.push_front(num);
        }
    }

    return numbers.front();
}

// 연산자를 백트래킹 방식으로 선택한다.
void makeZero(int idx, int cntOper, int N) {
    if (idx == cntOper) {
        if (calculate(N) == 0) {
            for (int i = 0; i < opers.size(); i++) {
                cout << (i+1);
                cout << opers[i];
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

    // 재귀함수 호출
    makeZero(0, N-1, N);

    return 0;
}