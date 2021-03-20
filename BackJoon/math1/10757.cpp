#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> stringToNumber(const string& target) {
    vector<int> numberVector;
    for (auto ele : target) {
        numberVector.push_back(ele - '0');
    }
    return numberVector;
}

vector<int> vectorSum(const string& a, const string& b) {
    vector<int> numberSum;

    int index = 0;
    while (true) {
        int targetSum = 0;

        if (index < a.size()) {
            targetSum += a.at(index);
        }

        if (index < b.size()) {
            targetSum += b.at(index);
        }

        if (index >= a.size() && index >= b.size()) break;

        numberSum.push_back(targetSum);
    }

    int idx = 0;
    while (true)
        

        if (numberSum[idx] >= 10) {
            numberSum[idx+1] += (numberSum[idx] % 10);
            numberSum[idx] %= 10;
        }
        idx++;
    }
}

void printSum(const vector<int>& numberSum) {

}

int main() {

    string a, b;

    vector<int> aNumber = stringToNumber(a);
    vector<int> bNumber = stringToNumber(b);

    vector<int> numberSum = vectorSum(a, b);
    printSum(numberSum);

    return 0;
}