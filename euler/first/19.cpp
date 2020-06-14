#include <iostream>

using namespace std;

int nowDay = 1;
int result = 0;
int usualMonthDate[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int unusualMonthDate[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isUnusual(int year) {
    if (year % 400 != 0 && year % 100 == 0) {
        return false;
    }
    else if (year % 400 == 0) {
        return true;
    }

    if (year % 4 == 0) {
        return true;
    }
    else {
        return false;
    }
}

int nextDay(int day, int year, int month, int date) {
    if (year != 1900 || month != 0 || date != 1) {
        if (day >= 6) return 0;
        return day + 1;
    }
    else {
        return day;
    }
}

int main() {

    for (int year = 1900; year <= 2000; year++) {
        if (isUnusual(year)) {
            for (int month = 0; month <= 11; month++) {
                for (int date = 1; date <= unusualMonthDate[month]; date++) {
                    nowDay = nextDay(nowDay, year, month, date);
                    if (nowDay == 0 && date == 1 && year != 1900) result++;
                    cout << year << " " << month + 1 << " " << date << " " << nowDay << endl;
                }
            }
        }
        else {
            for (int month = 0; month <= 11; month++) {
                for (int date = 1; date <= usualMonthDate[month]; date++) {
                    nowDay = nextDay(nowDay, year, month, date);
                    if (nowDay == 0 && date == 1 && year != 1900) result++;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}