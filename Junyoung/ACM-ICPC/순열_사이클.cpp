// https://www.acmicpc.net/problem/10451

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1000+1;
int N;
vector <int> perm(MAX_N);
vector <bool> visited(MAX_N);

void dfs(int n) {
	if (!visited[n]) {
		visited[n] = true;
		dfs(perm[n]);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		fill(perm.begin(), perm.end(), 0);
		fill(visited.begin(), visited.end(), false);

		scanf("%d", &N);
		for (int n = 1; n <= N; n++) {
			// 순열은 모든 수가 중복되지 않고 나타나야 함
			scanf("%d", &perm[n]);
		}
		
		int cycle_cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				dfs(i);
				cycle_cnt++;
			}
		}
		printf("%d\n", cycle_cnt);
	}
	return 0;
}