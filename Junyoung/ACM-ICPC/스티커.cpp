// https://www.acmicpc.net/problem/9465

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 100000 + 2;

int main() {
	int T;
	
	scanf("%d", &T);
	for(int t = 0 ; t < T; t++){
		int n;
		int st[2][MAX_N];
		int dp[2][MAX_N];
		
		scanf("%d", &n);
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &st[i][j]);
			}
		}
		
		int max_score = 0;
		dp[0][0] = st[0][0];
		dp[1][0] = st[1][0];
		dp[0][1] = dp[1][0] + st[0][1];
		dp[1][1] = dp[0][0] + st[1][1];
		for(int i = 2; i < n; i++){
			dp[0][i] = st[0][i] + max(dp[1][i-1], dp[1][i-2]);
			dp[1][i] = st[1][i] + max(dp[0][i-1], dp[0][i-2]);
			max_score = max(dp[0][i], max(dp[1][i], max_score));
		}
		printf("%d\n", max_score);
	}
	return 0;
}