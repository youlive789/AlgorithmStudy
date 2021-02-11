#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    map<string, int> table;
    map<string, int>::iterator it;

    for (int idx = 0; idx < n; idx++) {
        string tmp;
        cin >> tmp;
        table[tmp] = 0;
    }

    int answer = 0;
    for (int idx = 0; idx < m; idx++) {
        string tmp;
        cin >> tmp;

        it = table.find(tmp);
        if (it != table.end()) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}