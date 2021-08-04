#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int caseCount;
    scanf("%d\n", &caseCount);

    while (caseCount--) {
        string target;
        getline(cin, target);
        transform(target.begin(), target.end(), target.begin(), ::toupper);

        bool isPalindrome = true;
        int targetLength = target.size();
        for (int idx = 0; idx < targetLength / 2; ++idx) {
            if (target[targetLength-idx-1] != target[idx]) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}