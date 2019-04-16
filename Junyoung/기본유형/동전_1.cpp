// https://www.acmicpc.net/problem/2293

#include <stdio.h>

using namespace std;

int coin[10000 + 1];
int cnt[10000 + 1];	// 2차원 배열 사용 시 메모리 초과

int main() {
	int N, K;
	
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &coin[i]);
	}

	cnt[0] = 1;	// 동전 1개로 값을 만족하는 경우
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= coin[i]) {
                cnt[j] += cnt[j-coin[i]];
            }
		}
	}
	printf("%d", cnt[K]);
	return 0;
}