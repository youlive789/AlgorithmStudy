#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> fibo;
    fibo.push_back(1);

    vector<int> num;
    num.push_back(1);

    vector<int> tmp;

    unsigned int idx = 2;
    while (true) {

        tmp = fibo;

        for (int i = 0; i < num.size(); i++) {
            fibo[i] += num[i];
        }

        for (int i = 0; i < fibo.size(); i++) {
            if (fibo[i] >= 10) {
                int carry = fibo[i] / 10;
                fibo[i] %= 10;

                if (i == fibo.size() - 1) {
                    fibo.push_back(carry);
                }
                else {
                    fibo[i+1] += carry;
                }
            }
        }
        idx++;

        if (fibo.size() >= 1000) break;

        num = tmp;
    }

    cout << "index : " << idx << endl;
    for (int num : fibo) cout << num;
    
    cout << endl;
}



