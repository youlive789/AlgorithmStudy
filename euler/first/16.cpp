#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <string>
#include <cmath>

using namespace std;

int main() {

    // double test = 11;
    // double tmp = floor(11/2);
    // double rest = test - (tmp * 2);
    // cout << tmp << " " << rest << endl;

    
    double test = pow(2, 1000);
    ostringstream numberStream;
    numberStream << fixed << setprecision(numeric_limits<double>::digits10) << test;
    string number = numberStream.str();

    unsigned long long result = 0;

    cout << test << endl;

    for (char num : number) {
        result += (num - '0');
    }

    cout << result << endl;

    return 0;
}