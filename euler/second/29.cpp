#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

string powStr(const int& a, const int& b) {
    vector<int> target;
    target.push_back(a);

    for (int idx = 1; idx < b; idx++) {
        
        // 첫째 자리에서 곱셈연산
        for (int i = 0; i < target.size(); i++) {
            target[i] *= a;
        }

        // 자리수 연산
        for (int i = 0; i < target.size(); i++) {
            int num = target[i];
            if (num >= 10) {
                int carriage = num / 10;
                num %= 10;
                target[i] = num;
                if (i == target.size() - 1) {
                    target.push_back(carriage);
                }
                else {
                    target[i+1] += carriage;
                }
            }
        }
    }

    ostringstream oss;
    copy(target.begin(), target.end()-1, ostream_iterator<int>(oss, ","));
    oss << target.back();

    return oss.str();
}

int comb(const int& number) {

    set<string> numberSets;

    for (int i = 2; i <= number; i++) {
        for (int j = 2; j <= number; j++) {
            string t  = powStr(i, j);
            numberSets.insert(t);
        }
    }

    return numberSets.size();
}

int main() {

    cout << comb(100) << endl;
    return 0;
}