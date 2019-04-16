// https://www.acmicpc.net/problem/2231

#include <stdio.h>
#define MAX_N 1000000

using namespace std;

int main() {
	int N, creat;

	scanf("%d", &N);
	for (creat =1; creat <= MAX_N; creat++) {
		int sum = creat;
		for (int i = creat; i; i /= 10) sum += i % 10;
		if (sum == N)	break;
	}
	printf("%d", (creat <= MAX_N) ? creat : 0);

	return 0;
}