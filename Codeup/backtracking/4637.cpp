#include <iostream>
#include <vector>

using namespace std;

class Country {
private:
    int countryCode;
    int countryTable[6];
public:
    Country(const int& countryCode) : countryCode(countryCode) {
        this->countryTable[countryCode] = -1;
    }

    void win() {}

    void draw() {}

    void lose() {}
};

int main() {

    return 0;
}
