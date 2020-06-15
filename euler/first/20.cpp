#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> resultTable;
    resultTable.push_back(1);

    for (int num = 1; num <= 100; num++) {

        for (int idx = 0; idx < resultTable.size(); idx++) {
            resultTable[idx] *= num;
        }
        
        for (int idx = 0; idx < resultTable.size(); idx++) {
            if (resultTable[idx] >= 10) {

                int carry = resultTable[idx] / 10;
                resultTable[idx] %= 10;

                if (idx == resultTable.size() - 1) {
                    resultTable.push_back(carry);
                }
                else {
                    resultTable[idx+1] += carry;
                }
            }
        }
        
    }

    int result = 0;
    for (int num : resultTable) {
        result += num;
    }
    cout << result << endl;

    return 0;
}