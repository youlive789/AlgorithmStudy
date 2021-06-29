#include <iostream>

using namespace std;

int main() {

    int caseCount;
    cin >> caseCount;

    while (caseCount--) {
        int yonsei = 0, korea = 0;
        for (int i = 0; i < 9; ++i) {
            int yonseiScore, koreaScore;
            cin >> yonseiScore >> koreaScore;

            yonsei += yonseiScore;
            korea += koreaScore;
        }

        if (yonsei > korea) {
            cout << "Yonsei" << "\n";
        }
        else if (yonsei == korea) {
            cout << "Draw" << "\n";
        }
        else {
            cout << "Korea" << "\n";
        }
    }

    return 0;
}