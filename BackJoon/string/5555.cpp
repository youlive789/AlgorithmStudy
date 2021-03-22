#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main() {

    string target;
    cin >> target;

    int count;
    cin >> count;

    int answer = 0;
    while (count--) {
        deque<char> container;
        
        string haystack;
        cin >> haystack;
        
        for (int i = 0; i < haystack.size(); ++i) {
            container.push_back(haystack.at(i));
        }

        bool isFound = false;
        for (int i = 0; i < haystack.size(); ++i) {
            string output(container.begin(), container.end());
            if (output.find(target) != string::npos) {
                isFound = true;
            }
            rotate(container.begin(), container.begin() + 1, container.end());
        }

        if (isFound) answer++;
    }

    cout << answer << endl;

    return 0;
}