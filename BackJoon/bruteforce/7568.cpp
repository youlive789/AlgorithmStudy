#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main() {

    int cases;
    cin >> cases;

    vector<pair<int,int>> bodyTable;
    vector<int> rank;

    while (cases--) {
        int weight, length;
        cin >> weight >> length;
        bodyTable.push_back(make_pair(weight, length));
        rank.push_back(1);
    }

    for (int i = 0; i < bodyTable.size(); i++) {
        for (int j = i+1; j < bodyTable.size(); j++) {
            if (bodyTable[i].first > bodyTable[j].first && bodyTable[i].second > bodyTable[j].second) {
                rank[j]++;
            }
            else if (bodyTable[i].first < bodyTable[j].first && bodyTable[i].second < bodyTable[j].second) {
                rank[i]++;
            }
        }
    }

    for (auto num : rank) {
        cout << num << endl;
    }

    return 0;
}