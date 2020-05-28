#include<stdio.h>
#include<algorithm>

using namespace std;

int n,a,b,m,arr[21];

// reference : https://howtoliveworldnice.tistory.com/m/75

int solve(int k,int a,int b){
    if(k>m)
        return 0;
    int x=0,y=0,a_=a,b_=b;
    if(k>0)
        x=abs(a-arr[k]),y=abs(b-arr[k]),a_=arr[k],b_=arr[k];
    return min(x+solve(k+1,a_,b),y+solve(k+1,a,b_));
}
int main(){
    scanf("%d%d%d%d",&n,&a,&b,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",arr+i);
    printf("%d",solve(0,a,b));
}
