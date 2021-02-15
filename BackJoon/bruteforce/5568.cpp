#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void combNumber(int idx, int selectCount, set<int>& numberSet, vector<string>& comb, vector<string>& container) {
    if (idx >= container.size()) return;
    
    if (selectCount == 0) {
        string target = "";
        for (auto ele : comb) {
            target += ele;
        }
        numberSet.insert(stoi(target));
        return;
    }
    else {
        for (int i = 0; i < container.size(); i++) {
            if (i != idx) {
                comb.push_back(container.at(i));
                combNumber(i, selectCount-1, numberSet, comb, container);
                comb.pop_back();
            }
        }
    }
}

int main() {

    int size, selectCount;
    cin >> size >> selectCount;

    set<int> numberSet;
    vector<string> container, comb;
    for (int i = 0; i < size; i++) {
        string tmp;
        cin >> tmp;
        container.push_back(tmp);
    }

    combNumber(0, selectCount, numberSet, comb, container);

    cout << numberSet.size() << endl;

    return 0;
}