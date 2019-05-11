#include <iostream>

// 들고 갈 수 있는 최소 봉투 개수를 리턴한다.
int calcDivision(const int& number) {
    // 만약 number가 5의 배수라면
    if (number % 5 ==0) {
        // number / 5 를 리턴한다.
        return number / 5;
    }
    // 만약 number가 3의 배수라면
    else if (number % 3 == 0) {
        // number / 3 을 리턴한다.
        return number / 3;
    }      
    // 만약 number % 5가 3의 배수라면
    else if ( (number % 5) % 3 == 0 ) {
        // (number / 5) + (number % 5) / 3을 리턴한다.
        return (number / 5) + ((number % 5) / 3);
    }
    // 만약 number % 3가 5의 배수라면
    else if ( (number % 3) % 5 == 0 ) {
        // (number / 3) + (number % 3) / 5를 리턴한다.
        return (number / 3) + ((number % 3) / 5);
    }
    // 그 외의 경우
    else {
        int fiveDivision = (number / 5) - 1;
        int threeDivision = (number / 3) - 1;
        // number / 5 - 1만큼 반복 
        for (int firstIndex = 1; firstIndex <= fiveDivision; ++firstIndex) {
            // number / 3 - 1만큼 반복
            for (int secondIndex = 1; secondIndex <= threeDivision; ++threeDivision) {
                // 만약 i * 5 + j * 3 이 number와 같다면
                if ( (firstIndex * 5) + (secondIndex * 3) == number ) {
                    // i + j 를 리턴한다.
                    return firstIndex + secondIndex;
                }
                // 다른경우 -1을 리턴한다.
                else {
                    return -1;
                }
            }
        }
    }
}

int main() {
    int testNumber;
    std::cin>>testNumber;
    std::cout << calcDivision(6) << std::endl;
    return 0;
}