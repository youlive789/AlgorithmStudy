#include <stdio.h>

int memo[301]={0};	//메모 
int stairs[301] ={0};	//계단값 저장

int mymax(int a, int b){
	return a>b? a:b;
}

int recur(int a){
	if(a<0) return 0;
	if(a==1) return memo[1] = stairs[1];
	if(a==2) return memo[2] = stairs[1] + stairs[2];
	if(memo[a]!=0) return memo[a];
	else return memo[a] = mymax(recur(a-3)+stairs[a-1], recur(a-2))+stairs[a];
}

int main(){
	
	int a, b;
	scanf("%d", &a);
	for(int i=1;i<a+1;++i){
		scanf("%d", &stairs[i]);
	}
	
	printf("%d\n", recur(a));
	
	return 0;
}