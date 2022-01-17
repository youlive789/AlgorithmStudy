#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}


int main() {

    map<char, int> counter;

    char inputChar;
    while ((inputChar = getchar()) != EOF) {
        putchar(inputChar);
        if (counter.find(inputChar) != counter.end()) {
            counter[inputChar] = 1;
        }
        else {
            counter[inputChar]++;
        }
    }
    vector<pair<char, int>> vec( counter.begin(), counter.end() );
    sort(vec.begin(), vec.end(), cmp);

    int maximum = 0;
    for (const auto &item : vec) {
        if (maximum == 0) {
            maximum = item.second;
        }

        if (item.second != maximum) break;
        printf("%c", item.first);
    }

    return 0;
}