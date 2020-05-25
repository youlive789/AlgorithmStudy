#include <iostream>
#include <vector>

using namespace std;

bool block[20];

int main() {

    int N, firstOpen, secondOpen, cases;
    cin >> N >> firstOpen >> secondOpen >> cases;

    int tmp;
    vector<int> target;
    while (cases--) {
        cin >> tmp;
        target.push_back(tmp);
    }
        
    return 0;
}