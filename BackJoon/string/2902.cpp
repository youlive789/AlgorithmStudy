#include <iostream>
#include <string>

using namespace std;

int main() {

    string target, answer;
    cin >> target;

    for (char ele: target) {
        if (ele >= 65 && ele <= 90) {
            answer += ele;
        }
    }

    cout << answer << endl;

    return 0;
}