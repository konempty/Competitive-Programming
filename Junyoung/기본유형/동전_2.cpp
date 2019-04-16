// https://www.acmicpc.net/problem/2294

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 2;

vector<int> coin;
int cnt[MAX];

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	
	coin.resize(N);
	for(int i =0; i < N; i++){
		scanf("%d", &coin[i]);
	}
	sort(coin.begin(), coin.end());
	
	for(int k = 1; k <= K; k++){
		cnt[k] = MAX;
		for(int n = 0; n < N; n++){
			if(k < coin[n])	break;
			cnt[k] = min(cnt[k], cnt[k-coin[n]]+1);
		}
	}
	printf("%d\n", (cnt[K] == MAX) ? -1 : cnt[K]);
	
	return 0;
}