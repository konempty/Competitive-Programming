// https://www.acmicpc.net/problem/1005

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000 + 3;

int build_t[MAX_N];
vector <vector<int>> build_o;
int dp[MAX_N];

int dfs(int w) {
	int time = 0;

	int len = build_o[w].size();
	for (int i = 0; i < len; i++) {
		int b = build_o[w][i];
		time = max(time, (dp[b] != -1) ? dp[b] : dfs(b));
	}
	return dp[w] = build_t[w] + time;
}

int main() {
	int T;

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int N, K, W;
		scanf("%d %d", &N, &K);
		// init
		memset(build_t, 0, sizeof(int)*MAX_N);
		build_o.clear();
		build_o.resize(N+2);
		memset(dp, -1, sizeof(int)*MAX_N);

		for (int n = 1; n <= N; n++) {
			scanf("%d", &build_t[n]);
		}
		for (int k = 0, a,b; k < K; k++) {
			scanf("%d %d", &a, &b);
			build_o[b].push_back(a);
		}
		scanf("%d", &W);
		printf("%d\n", dfs(W));
	}
	return 0;
}
