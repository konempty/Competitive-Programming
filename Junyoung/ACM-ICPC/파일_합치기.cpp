#include <cstdio>
#include <algorithm>
using namespace std;

#define FOR(i,s,n) for(int i = s; i < n; i++)
const int MAX_K = 500 + 1;
const int MAX_VAL = 2e9;

int cost[MAX_K];
int sum[MAX_K];			// [1,K] 구간의 합 
int dp[MAX_K][MAX_K];	// [a,b] 구간의 LCS

int dnc(int s, int e) {
	if (dp[s][e] < MAX_VAL)	return dp[s][e];
	if (s == e)		return dp[s][e] = 0;
	if (s+1 == e)	return dp[s][e] = cost[s] + cost[e];

	FOR(m, s, e) {
		dp[s][e] = min(dp[s][e], dnc(s, m) + dnc(m+1, e));
	}
	return dp[s][e] += sum[e]-sum[s-1];	// 마지막 합 연산
}

int main() {
	int T;

	scanf("%d", &T);
	FOR(t, 0, T){
		int K;
		
		scanf("%d", &K);
		FOR(i, 1, K+1) {
			scanf("%d", &cost[i]);
			sum[i] = sum[i-1] + cost[i];
		}
		FOR(i, 1, K+1)	FOR(j, 1, K+1) {
			dp[i][j] = MAX_VAL;
		}
		printf("%d\n", dnc(1, K));
	}
	return 0;
}