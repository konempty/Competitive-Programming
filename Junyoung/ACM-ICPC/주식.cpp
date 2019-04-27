// https://www.acmicpc.net/problem/11501

#include <cstdio>
using namespace std;

typedef long long ll;
const int MAXN = 1000000+2;

int main() {
	int T;
	
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		int N;
		int stock[MAXN];
		
		scanf("%d", &N);
		for(int i = 0; i < N; i++)	scanf("%d", &stock[i]);
		
		int max = 0;
		ll profit = 0;
		// O(N). 뒤에서부터 순회
		for(int i = N-1; i >= 0; i--){
			if(stock[i] > max)	max = stock[i];
			else profit += max-stock[i];	
		}
		printf("%lld\n", profit);
	}
    return 0;
}
