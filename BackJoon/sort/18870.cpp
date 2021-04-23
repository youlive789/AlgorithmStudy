#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int count;
    cin >> count;

    set<int> cord_set;
    int* cords = new int[count];
    for (int idx = 0; idx < count; ++idx) {
        int tmp;
        scanf("%d", &tmp);
        cords[idx] = tmp;
        cord_set.insert(tmp);
    }

    map<int,int> cord_table;
    set<int>::iterator iter = cord_set.begin();
    for (int i = 0; i < cord_set.size(); ++i) {
        cord_table[*iter] = i;
        advance(iter, 1);
    }

    for (int i = 0; i < count; ++i) {
        cout << cord_table[cords[i]] << " ";
    }
    cout << endl;

    return 0;
}