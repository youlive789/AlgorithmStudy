#include <iostream>
#include <string>

using namespace std;

bool canCoverWithA(const int& point, string& target) {
    if (point+4 > target.size()) return false;

    bool canCover = true;
    for (int i = point; i < point+4; ++i) {
        if (target.at(i) != 'X') {
            canCover = false;
            break;
        }
    }
    return canCover;
}

bool canCoverWithB(const int& point, string& target) {
    if (point+2 > target.size()) return false;

     bool canCover = true;
    for (int i = point; i < point+2; ++i) {
        if (target.at(i) != 'X') {
            canCover = false;
            break;
        }
    }
    return canCover;
}

void coverWithA(const int& point, string& target) {
    fill(target.begin() + point, target.begin() + point + 4, 'A');
}

void coverWithB(const int& point, string& target) {
    fill(target.begin() + point, target.begin() + point + 2, 'B');
}

int main() {

    string target;
    cin >> target;

    int position = 0;
    while (position < target.size() - 1) {
        if (target.at(position) == '.') {
            position++;
            continue;
        }

        if (canCoverWithA(position, target)) {
            coverWithA(position, target);
            position += 4;
            continue;
        }
        
        if (canCoverWithB(position, target)) {
            coverWithB(position, target);
            position += 2;
            continue;
        }

        position++;
    }

    if (target.find('X') == string::npos) {
        cout << target << endl;
    }
    else {
        cout << -1 << endl;
    }
    

    return 0;
}