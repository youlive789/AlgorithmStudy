#include <iostream>
#include <vector>

// 한수판별
bool hanNumber(const int & number) {

    // 자리수 계산을 위한 임시변수
    int tempNumber = number;

    // 자리수를 저장하기위한 컨테이너
    std::vector<int> digits;

    // 입력 받은 정수가 0이 아니라면 반복
    while(tempNumber != 0) {
        // 자리수를 구하고 저장한다.
        digits.push_back(tempNumber % 10);
        // 입력 받은 정수를 10으로 나눈 값으로 업데이트한다.
        tempNumber /= 10;
    }

    // 차이를 구하기 위한 자리수 변수
    int currentDigit = -99999;

    // 차이를 저장하기 위한 변수
    int diff = -99999;

    // 등차수열을 저장한 개수만큼 반복
    for (auto &digit : digits) {

        // 저장해놓은 자리수 두개를 추출하여 차이를 구한다.
        // 첫번째 자리수 추출
        if (currentDigit == -99999) {
            currentDigit = digit;
            continue;
        }

        // 두번째 자리수 추출 후 차이계산
        if (diff == -99999) {
            diff = currentDigit - digit;
            currentDigit = digit;
            continue;
        }

        // 다음 자리수를 추출하여 이전 자리수의 차이를 구한다.
        // 만약 현재 차이가 이전에 계산한 차이와 다르다면
        if (diff != currentDigit - digit) {
            // 한수가 아님
            return false;
        }
    }

    // 한수임  
    return true;
}

int main() { 

    int count = 0;
    int rangeNumber;
    std::cin >> rangeNumber;

    for (int index = 1; index <= rangeNumber; ++index){
        if (hanNumber(index)) {
            count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}