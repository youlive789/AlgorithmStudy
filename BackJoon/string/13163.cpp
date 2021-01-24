#include <iostream>
#include <string>
#include <sstream>
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

    int caseCount;
    cin >> caseCount;
    cin.ignore();

    for (int idx = 0; idx < caseCount; idx++) {

        string input;
        getline(cin, input);

        string answer = "god";
        vector<string> splited = split(input, ' ');
        for (int i = 1; i < splited.size(); i++) {
            answer += splited.at(i);
        }

        cout << answer << endl;
    }

    return 0;
}