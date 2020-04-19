#include <iostream>
using namespace std;

int N, cnt;
int col[15 + 1];

//배치 가능한지 여부
bool promising(int i)
{
    int k = 1;
    bool flag = true;
    while (k < i && flag)
    {
        //같은 열이거나 대각선이라면 배치 못함
        if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
            flag = false;
        k++;
    }
    return flag;
}

void queens(int i)
{
    if (promising(i))
    {
        //판이 완성
        if (i == N)
            cnt++;
        else
            //해당 열에 배치
            for (int j = 1; j <= N; j++)
            {
                col[i + 1] = j;
                queens(i + 1);
            }
    }
}

int main(void)
{
    /*
    1. promising 함수를 통해 해당 칸에 퀸을 배치할 수 있는지 여부를 판단합니다.
    2. promising 함수가 true를 반환할 경우
        i) N 번째 열까지 도달했을 경우 완성된 체스판이므로 개수를 셉니다
        ii) 해당 열 모든 칸에 퀸을 배치하면서 가능성을 판단합니다다
    3. 총 완성된 체스판의 수를 출력합니다.
    */

    cin.tie(0); //cin 실행속도 향상
    cin >> N;
    queens(0);
    cout << cnt << "\n";
    return 0;
}