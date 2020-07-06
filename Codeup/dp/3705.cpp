#include <stdio.h>
 
int main(void){
 
    int N;
    int number[100010] = {};
    int Dp[100010] = {};
    int max;
    scanf("%d", &N);
 
    for (int i = 1; i <= N; i++)
        scanf("%d", &number[i]);
 
    for (int i = 1; i <= N; i++)
    {
        
        if (Dp[i - 1] + number[i] > number[i]){
            Dp[i] = Dp[i - 1] + number[i];
        }
        else
        {
            Dp[i] = number[i];
        }
    
    }
    max = Dp[1];
    for (int i = 2; i <= N; i++)
            if (max < Dp[i])
                max = Dp[i];
 
    printf("%d\n", max);
}