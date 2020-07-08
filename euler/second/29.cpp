#include <set>
#include <string>
#include <iostream>

using namespace std;

string powStr(const int& a, const int& b) {
    string target = "";
    target.append(to_string(a));

    for (int idx = 1; idx < b; idx++) {
        
        // 첫째 자리에서 곱셈연산
        for (int i = 0; i < target.size(); i++) {
            int nowNum = target[i] - '0';
            nowNum *= a;
            target[i] = nowNum + '0';
        }

        // 자리수 연산
        for (int i = 0; i < target.size(); i++) {
            int num = target[i] - '0';
            if (num >= 10) {
                int carriage = num / 10;
                num %= 10;
                target[i] = num + '0';
                if (i == target.size() - 1) {
                    target.append(to_string(carriage));
                }
                else {
                    target[i+1] += carriage;
                }
            }
        }
    }

    return target;
}

int comb(const int& number) {

    set<string> numberSets;

    for (int i = 2; i <= number; i++) {
        for (int j = 2; j <= number; j++) {
            numberSets.insert(powStr(i, j));
        }
    }

    return numberSets.size();
}

int main() {

    cout << comb(100) << endl;
    return 0;
}