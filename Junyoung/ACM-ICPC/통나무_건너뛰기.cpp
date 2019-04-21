// https://www.acmicpc.net/problem/11497

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 2;

int main() {
	int T;
	
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		int N;
		int L[MAXN];
		
		scanf("%d", &N);
		for(int n = 0; n < N; n++)	scanf("%d", &L[n]);
		sort(L, L+N);
		
		// 왼 오 순으로 번갈아 배치시킴 -> 최소
		// [0]-[2]-[4] [3]-[1]
		//  2   5   9   7   4
		int dist = 0;
		for(int i = 2; i < N; i++){
			dist = max(dist, L[i]-L[i-2]);
		}
		printf("%d\n", dist);
	}
    return 0;
}
