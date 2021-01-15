#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {

    int testCount;
    cin >> testCount;

    for (int i = 0; i < testCount; i++) {
        map<string, set<string>> fashion;

        int wearCount;
        cin >> wearCount;
        for (int idx = 0; idx < testCount; idx++) {
            string wear, type;
            cin >> type;

            if (fashion.find(type) == fashion.end()) {
                fashion[type] = set<string>();
            }

            fashion[type].insert(wear);
        }

        
        
    }



    return 0;
}