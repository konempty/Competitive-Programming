// https://www.acmicpc.net/problem/2579

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 300+2;

int N;
int cost[MAX_N];
int dp[MAX_N];

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		scanf("%d", &cost[n]);
	}

	dp[1] = cost[1];
	dp[2] = cost[1] + cost[2];
	for (int i = 3; i <= N; i++) {
		// ? ? 0 1
		// ? 0 1 1
		dp[i] = max(dp[i-2] + cost[i], dp[i-3] + cost[i-1] + cost[i]);
	}
	printf("%d", dp[N]);
	return 0;
}