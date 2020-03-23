#include <iostream>

using namespace std;

/*                  
0    1     2    3    4     5   6    7    8    9    10   11   12   13   14   15   16  17   18
666 1666 2666 3666 4666 5666 6661 6662 6663 6664 6665 6666 6667 6668 6669 7666 8666 9666 10666 

11666 12666 13666 14666 15666 16661 16662 16663 16664 16665 16666 16667 16668 16669 17666 18666 19666

일반적인 경우
    (N % 19 - 1) * 1000 + 666
6이 포함된 경우 (5 <= N % 18 <= 13)
    (N % 19 - 1) * 666 + (N - 4)

*/

int getMovie(const int& number) {
    if ( (number % 19) >= 7 && (number % 19) <= 15 ) {
        return ( (number / 19) ) * 10000 + 6660 + ( number - 6);
    }
    else {
        return ( (number % 19) - 1 ) * 1000 + 666;
    }
}

int main() {

    int testNumber;
    cin >> testNumber;

    cout << getMovie(testNumber) << endl;

    return 0;
}