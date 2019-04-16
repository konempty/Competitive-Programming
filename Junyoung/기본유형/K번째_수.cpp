// https://www.acmicpc.net/problem/1300

#include <stdio.h>
#include <algorithm>
using namespace std;

int N, K;

int bi_search(int l, int r){
	if (l > r) return l;

	int cnt = 0;
	int m = (l + r) / 2;
	for (int i = 1; i <= N; i++) {
		cnt += min(m/i, N);
	}
	return (cnt < K) ? bi_search(m+1, r) : bi_search(l, m-1);
}

int main(){
	scanf("%d %d", &N, &K);
	printf("%d", bi_search(1, K));
	return 0;
}