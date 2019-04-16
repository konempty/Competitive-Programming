// https://www.acmicpc.net/problem/2293

#include <cstdio>
using namespace std;

const int MAX = 10000+2;
int coin[MAX];
int cnt[MAX];

int main() {
	int N, K;
	
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &coin[i]);
	}

	cnt[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= coin[i])	cnt[j] += cnt[j-coin[i]];
		}
	}
	printf("%d", cnt[K]);
	return 0;
}