// https://www.acmicpc.net/problem/14501

#include <cstdio>
#include <algorithm>
using namespace std;

#define FOR(i,s,n) for(int i = s; i < n; i++)
const int MAXN = 15+2;

int T[MAXN], P[MAXN];
int dp[MAXN];

int main(){
	int N;
	scanf("%d", &N);
	FOR(i, 1, N+1)	scanf("%d %d", &T[i], &P[i]);
	
	for(int d = N; d >= 1; d--){
		int prev = d+T[d];
		dp[d] = (prev > N+1) ? dp[d+1] : max(dp[d+1], dp[prev]+P[d]);
	}
	printf("%d\n", dp[1]);
	
	return 0;
}