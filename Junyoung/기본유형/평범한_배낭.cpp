// https://www.acmicpc.net/problem/12865

#include <cstdio>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i = 1; i <= n; i++)
const int MAXN = 100+2;
const int MAXT = 100000+2;

int W[MAXN];
int V[MAXN];
int dp[MAXN][MAXT];

int main() {
	int N, K;
	
	scanf("%d %d", &N, &K);
	FOR(i,N)	scanf("%d %d", &W[i], &V[i]);
	
	FOR(i,N) FOR(j,K){
		if(W[i] <= j){
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
		} else {
			dp[i][j] = dp[i-1][j];
		}
	}
	printf("%d\n", dp[N][K]);
	return 0;
}
