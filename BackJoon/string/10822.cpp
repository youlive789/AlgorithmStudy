#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

int main() {

    string target;
    cin >> target;

    unsigned long long answer = 0;
    vector<string> splited = split(target, ',');
    for (auto number : splited) {
        answer += stoi(number);
    }

    cout << answer << endl;

    return 0;
}