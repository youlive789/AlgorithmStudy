#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> rgb;
    int cases = 0, sum = 0, lastChoice = -1, trigger = 0;
    cin >> cases;
    while(cases--) {
        
        for (int i = 0; i < 3; i++) {
            int tmp;
            cin >> tmp;
            rgb.push_back(tmp);
        }

        if (lastChoice != -1) {
            rgb.erase(rgb.begin() + lastChoice);
        }

        vector<int>::iterator min = min_element(begin(rgb), end(rgb));
        sum += *min;

        if (lastChoice == 0) {
            trigger = 1;
        }
        else if (lastChoice == 1) {
            if (distance(begin(rgb), min) == 1)
                trigger = 1;
        }
        else if (lastChoice == 2) {
            trigger = 0;
        }

        lastChoice = distance(begin(rgb), min) + trigger;

        rgb.clear();
    }

    cout << sum << endl;

    return 0;
}