#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    map<char, int> table = {
        {'C', 0}, {'A', 0}, {'M', 0}, {'B', 0}, {'R', 0},
        {'I', 0}, {'D', 0}, {'G', 0}, {'E', 0}
    };

    string target;
    cin >> target;

    string answer;
    for (auto ele : target) {
        if (table.find(ele) == table.end()) {
            answer += ele;
        }
    }

    cout << answer << endl;

    return 0;
}