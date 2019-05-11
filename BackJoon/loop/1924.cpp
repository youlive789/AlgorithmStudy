#include <iostream>
/**
 * 첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 
 * 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 
 * 2월은 28일까지 있다.
 */

// 테이블에 모든 요일 정보를 세팅해놓고 주어진 날짜를 탐색한다. -> 완전탐색
int main() {

    // 입력처리
    int month;
    int day;
    std::cin >> month;
    std::cin >> day;

    // 달력세팅
    int* calendar[13];
    int daysList[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayCount = 1;

    for (int monthIndex = 1; monthIndex <= 12; ++monthIndex) {
        calendar[monthIndex] = new int[daysList[monthIndex] + 1];
        for (int daysIndex = 1; daysIndex <= daysList[monthIndex]; ++daysIndex) {
            calendar[monthIndex][daysIndex] = dayCount;
            dayCount + 1 == 7 ? dayCount = 0 : dayCount += 1; 
        }
    }

    // 결과출력
    switch (calendar[month][day]) {
        case 0 : std::cout << "SUN" << std::endl; break;
        case 1 : std::cout << "MON" << std::endl; break;
        case 2 : std::cout << "TUE" << std::endl; break;
        case 3 : std::cout << "WED" << std::endl; break;
        case 4 : std::cout << "THU" << std::endl; break;
        case 5 : std::cout << "FRI" << std::endl; break;
        case 6 : std::cout << "SAT" << std::endl; break;
    }

    return 0;
}