#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool palindrome(const string& target) {
    int length = target.size();
    int half = length / 2;
    int evenOddTrigger = length % 2;

    string front = target.substr(0, half);
    string back = target.substr(half+evenOddTrigger, half);
    reverse(back.begin(), back.end());
    
    if (front == back) {
        return true;
    }
    return false;
}

int main() {

    string target;
    cin >> target;

    if (palindrome(target)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}