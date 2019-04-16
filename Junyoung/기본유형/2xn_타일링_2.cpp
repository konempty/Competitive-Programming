// https://www.acmicpc.net/problem/11727

#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 2;
int dp[MAX];

int main(){
	int N;
	scanf("%d", &N);
	
	dp[1] = 1;	dp[2] = 3;
	for(int i = 3; i <= N; i++){
		dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007;
	}
	printf("%d\n", dp[N]);
	
	return 0;
}