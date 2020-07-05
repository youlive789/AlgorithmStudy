#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

int numbers[100000];

int dfs(int nowIndex, int countNumber) {
    if (nowIndex == countNumber) {
        return numbers[countNumber-1];
    }

    int currentSum = 0, currentAnswer = numeric_limits<int>::min();
    for (int i = nowIndex; i < countNumber; i++) {
        currentSum += numbers[i];
        currentAnswer = max(currentAnswer, currentSum);
    }

    return max(currentAnswer, dfs(nowIndex + 1, countNumber));
    
}

int main() {

    int cases;
    scanf("%d", &cases);

    int sum = 0;
    for (int i = 0; i < cases; i++) {
        int tmp;
        scanf("%d", &tmp);
        
        numbers[i] = tmp;
    }

    printf("%d", dfs(0, cases));

    return 0;
}