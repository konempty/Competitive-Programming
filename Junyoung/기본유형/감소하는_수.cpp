// https://www.acmicpc.net/problem/1038

#include <stdio.h>

using namespace std;

const int MAX_DIGIT = 10;

int N;
int num[MAX_DIGIT];

void dfs(int idx, int digit) {
	if (N <= 0)	return;

	num[idx] = digit;
	if (idx == MAX_DIGIT-1){
		N--;
		return;
	}
	for (int i = 0; i < digit; i++) {
		dfs(idx+1, i);
	}
}

int main() {
	scanf("%d", &N);
	N++;
	for (int i = MAX_DIGIT-1; i >= 0; i--) {
		for (int j = 0; j < 10; j++) {
			dfs(i, j);
		}
	}

	if (N > 0)	return !printf("-1");

	for (int i = 0; i < MAX_DIGIT; i++) {
		if (!num[i] && i < MAX_DIGIT-1)	continue;
		printf("%d", num[i]);
	}

	return 0;
}