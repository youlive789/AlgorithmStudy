#include <iostream>

using namespace std;

int n;
char answer[7];

void dfs(int now) 
{
    if (now == n) {
        cout << answer << endl;
        return;
    }

    answer[now] = 'O';
    dfs(now + 1);
    answer[now] = 'X';
    dfs(now + 1);
}

int main() {

    cin >> n;
    dfs(0);

    return 0;
}