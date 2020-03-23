#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int sizeNumbers, score, result = -999;

void blackjack(vector<int> pickNumbers, int* numbers, int choice, int count) {
    // 기저사례: 3개를 뽑았으면 점수를 리턴한다.
    if (count == 3) {
        int sum = 0;
        for (auto nums : pickNumbers) {
            sum += nums;
        }

        if (sum <= score) {
            result = max(result, sum);
        }
        return; 
    } 

    for (int index = choice; index < sizeNumbers; index++) {
        pickNumbers.push_back(numbers[index]);
        blackjack(pickNumbers, numbers, index + 1, count + 1);
        pickNumbers.pop_back();
    }
}

int main() {

    cin >> sizeNumbers >> score;

    vector<int> pickNumbers;
    int numbers[sizeNumbers];
    for (int idx = 0; idx < sizeNumbers; idx++) {
        cin >> numbers[idx];
    }

    blackjack(pickNumbers, numbers, 0, 0);
    cout << result << endl;

    return 0;
}