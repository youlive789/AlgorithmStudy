#include <iostream>
#include <vector>

using namespace std;

class Country {
public:
    int countryCode;
    int countryMatchTable[6];

    Country(const int& countryCode) : countryCode(countryCode) {
        this->countryMatchTable[countryCode] = -1;
    }

    void win(Country & opponent, int scoreTable[18]) {
        scoreTable[countryCode] -= 1;
        scoreTable[opponent.countryCode + 2] -= 1;

        this->countryMatchTable[opponent.countryCode] = -1;
        opponent.countryMatchTable[this->countryCode] = -1;
    }

    void draw(Country & opponent, int scoreTable[18]) {
        scoreTable[countryCode + 1] -= 1;
        scoreTable[opponent.countryCode + 1] -= 1;
        
        this->countryMatchTable[opponent.countryCode] = -1;
        opponent.countryMatchTable[this->countryCode] = -1;
    }

    void lose(Country & opponent, int scoreTable[18]) {
        scoreTable[countryCode + 2] -= 1;
        scoreTable[opponent.countryCode] -= 1;

        this->countryMatchTable[opponent.countryCode] = -1;
        opponent.countryMatchTable[this->countryCode] = -1;
    }
};

bool selected[6];

void dfs(int idx, int cnt, Country * countries[6]) {
    if (cnt == 2) {
        for (int i = 0; i < 6; i++) {
            if (selected[i] == true) {
                cout << countries[i]->countryCode << " ";
            }
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < 6; i++) {
        if (selected[i] == true) continue;
        selected[i] = true;
        dfs(idx, cnt+1, countries);
        selected[i] = false;
    }
}

int main() {

    int scoreTable[18] = {5, 0, 0, 3, 0, 2, 2, 0, 3, 0, 0, 5, 4, 0, 1, 1, 0, 4};

    Country * countries[6];
    for (int i = 0; i < 6; i++) {
        countries[i] = new Country(i);
    }

    dfs(0, 0, countries);

    for (int i = 0; i < 6; i++)
        delete countries[i];



    return 0;
}
