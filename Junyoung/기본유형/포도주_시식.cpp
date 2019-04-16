#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 10000 + 1;
int wine[MAX_N];
int dp[MAX_N];

int main() {
	int N;
	
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &wine[i]);
	}

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i-1], dp[i-2] + wine[i]);
		dp[i] = max(dp[i], dp[i-3] + wine[i-1] + wine[i]);
	}
	printf("%d", dp[N]);
	
	return 0;
}