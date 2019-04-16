// https://www.acmicpc.net/problem/10989

#include <stdio.h>

const int MAX_N = 10000 + 1;

using namespace std;

int N;
int cnt[MAX_N];
int cnt_sum[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		cnt[num]++;
	}

	for (int n = 0, idx = 1; n < N; idx++) {
		int len = cnt[idx];
		for (int k = 0; k < len; k++) {
			printf("%d\n", idx);
			n++;
		}
	}
	return 0;
}