// https://www.acmicpc.net/problem/1654

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int K, N;
vector <int> lan;

int bi_search(ll s, ll e) {
	if (s > e)	return -1;

	int cnt = 0;
	ll m = (s + e) / 2;	// int 범위를 넘어설 수 있음

	for (int i = 0; i < K; i++) {
		cnt += lan[i] / m;
	}
	if (cnt >= N) {
		int next = bi_search(m+1, e);	// int 범위를 넘어설 수 있음
		return max(next, (int)m);	// 더 크게 잘랐을 때도 N이 나올 수 있음
	}
	return bi_search(s, m-1);
}

int main() {
	int max_lan = -1;
	scanf("%d %d", &K, &N);
	lan.resize(K);
	for (int k = 0; k < K; k++) {
		scanf("%d", &lan[k]);
		max_lan = max(max_lan, lan[k]);
	}
	printf("%d", bi_search(1, max_lan));

	return 0;
}