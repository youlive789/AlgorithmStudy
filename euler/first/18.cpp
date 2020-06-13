#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> split(string str, char delimiter) {
    vector<int> internal;
    stringstream ss(str);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        internal.push_back(stoi(temp));
    }
 
    return internal;
}

int answer = 0;

void findRoute(vector<vector<int>> table, int idx, int selected, int sum) {

    if (table.size() == idx) {
        if (sum > answer) answer = sum;
        return;
    }

    if (table[idx].size() == 1) {
        findRoute(table, idx + 1, 0, sum + table[idx][0]);
    }
    else {
        findRoute(table, idx + 1, selected, sum + table[idx][selected]);
        findRoute(table, idx + 1, selected + 1, sum + table[idx][selected + 1]);
    }
}

int main() {

    vector<vector<int>> table;

    ifstream fp("18.txt");
    if (fp.is_open()) {
        string tmp;
        while (getline(fp, tmp)) {
            table.push_back(split(tmp, ' '));
        }
    }

    for (vector<int> row : table) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    findRoute(table, 0, 0, 0);
    cout << answer << endl;

    return 0;
}
