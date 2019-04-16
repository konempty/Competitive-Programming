// https://www.acmicpc.net/problem/9020

#include <stdio.h>
#define MAXNUM 10000

int not_prime[MAXNUM];

void find_prime() {
	not_prime[0] = not_prime[1] = 1;
	for (int i = 2; i <= MAXNUM; i++) {
		if (not_prime[i])
			continue;
		for (int j = i * 2; j <= MAXNUM; j += i) {
			not_prime[j] = 1;
		}
	}
}

int main() {
	int T;

	find_prime();
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int N, flag = 0;
		int a, b;

		scanf("%d", &N);
		for (int i = N / 2; i < N; i++) {
			if (!not_prime[i] && !not_prime[N-i]) {
				printf("%d %d\n", N-i, i);
				break;
			}
		}
	}
	return 0;
}