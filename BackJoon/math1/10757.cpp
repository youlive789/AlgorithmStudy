#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stringToNumber(const string& target);
vector<int> vectorSum(const vector<int>& a, const vector<int>& b);
void printSum(const vector<int>& numberSum);

vector<int> stringToNumber(const string& target) {
    vector<int> numberVector;
    for (auto ele : target) {
        numberVector.push_back(ele - '0');
    }
    return numberVector;
}

vector<int> vectorSum(const vector<int>& a, const vector<int>& b) {
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
        index++;
    }

    int idx = 0;
    while (true) {
        if (numberSum[idx] >= 10) {

            if (idx == numberSum.size() - 1) {
                numberSum.push_back(0);
            }

            numberSum[idx+1] += (numberSum[idx] / 10);
            numberSum[idx] %= 10;
        }

        if (idx == numberSum.size() - 1 && numberSum[idx] < 10) break;
        idx++;
    }

    return numberSum;
}

void printSum(const vector<int>& numberSum) {
    for (int idx = numberSum.size() - 1; idx >=0; --idx) {
        cout << numberSum[idx];
    }
    cout << endl;
}

int main() {

    string a, b;
    cin >> a >> b;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> aNumber = stringToNumber(a);
    vector<int> bNumber = stringToNumber(b);

    vector<int> numberSum = vectorSum(aNumber, bNumber);
    printSum(numberSum);

    return 0;
}