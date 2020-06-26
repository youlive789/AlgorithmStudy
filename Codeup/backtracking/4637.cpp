#include <iostream>
#include <vector>

using namespace std;

class Country {
public:
    int countryCode;
    int countryScoreTable[3];
    int countryMatchTable[6];

    Country(const int& countryCode) : countryCode(countryCode) {
        this->countryMatchTable[countryCode] = -1;
    }

    void win(Country & opponent) {

    }

    void draw(Country & opponent) {

    }

    void lose(Country & opponent) {

    }
};

void dfs() {
    for (int i = 0; i < 6; i++) {
        // win
        // dfs
        // free

        // draw
        // dfs
        // free

        // lose
        // dfs
        // free
    }
}

int main() {

    return 0;
}
