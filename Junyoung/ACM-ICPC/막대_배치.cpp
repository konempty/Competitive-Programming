// https://www.acmicpc.net/problem/8895

#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX_N = 20 + 1;

int main() {
	long long dp[MAX_N][MAX_N][MAX_N];
	// 높이 N->1 순으로 막대 세우기
	dp[1][1][1] = 1;
	for(int n = 2; n < MAX_N; n++){
		for(int l = 1; l < MAX_N; l++){
			for(int r = 1; r < MAX_N; r++){
				dp[n][l][r] = dp[n-1][l-1][r];	// 왼쪽 추가
				dp[n][l][r] += dp[n-1][l][r-1];	// 오른쪽 추가
				dp[n][l][r] += dp[n-1][l][r] * (n-2);	// 가운데 추가
			}
		}
	}
	
	int T;
	scanf("%d", &T);
	for(int t = 0 ; t < T; t++){
		int N, L, R;
		scanf("%d %d %d", &N, &L, &R);
		printf("%lld\n", dp[N][L][R]);
	}
	return 0;
}