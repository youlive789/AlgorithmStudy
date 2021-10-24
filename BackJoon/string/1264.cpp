#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<char> targetArray = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    vector<char>::iterator it;

    while (true) {
        string sentence;
        getline(cin, sentence);

        if (sentence == "#") break;

        int count = 0;
        for (char ch : sentence) {
            it = find(targetArray.begin(), targetArray.end(), ch);
            if (it != targetArray.end()) {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}