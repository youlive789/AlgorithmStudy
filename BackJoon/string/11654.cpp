#include <iostream>

using namespace std;

int main() {

    char inputChar;
    cin >> inputChar;

    int result;
    result = static_cast<int>(inputChar);

    cout << result << endl;

    return 0;
}