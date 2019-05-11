#include <iostream>

// 들고 갈 수 있는 최소 봉투 개수를 리턴한다.
int calcDivision(const int& number) {

    int chk = 0;
    int sum = 0;

    // 배수관계가 아닐경우를 먼저 계산한다.
    int fiveDivision = (number / 5);
    int threeDivision = (number / 3);
    // number / 5 - 1만큼 반복 
    for (int firstIndex = 0; firstIndex <= fiveDivision; ++firstIndex) {
        // number / 3 - 1만큼 반복
        for (int secondIndex = 0; secondIndex <= threeDivision; ++secondIndex) {
            // 만약 i * 5 + j * 3 이 number와 같다면
            if ( (firstIndex * 5) + (secondIndex * 3) == number) {
                if (sum == 0 || sum > firstIndex + secondIndex) {
                    sum = firstIndex + secondIndex;
                }
            }
        }
    }
    
    if (sum) return sum;

    return -1;
    
}

int main() {
    int testNumber;
    std::cin>>testNumber;
    std::cout << calcDivision(testNumber) << std::endl;
    return 0;
}