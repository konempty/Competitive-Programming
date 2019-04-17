// https://www.acmicpc.net/problem/2805

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 1000000+2;

ll N, M;
ll l, r;
ll tree[MAXN];

int main(){	
	scanf("%lld %lld", &N, &M);
	
	l = 0, r = 0;
	for(int i = 0; i < N; i++){
		scanf("%lld", &tree[i]);
		r = max(r, tree[i]);
	}
	
	ll H = 0;
	while(l <= r){
		ll mid = (l+r)/2;	// int형 사용 시 overflow 발생 가능
		ll sum = 0;
		for(int i = 0; i < N; i++){
			sum += (tree[i] > mid) ? tree[i]-mid : 0;
		}
		if (sum >= M){	
			l = mid+1;
			H = max(H, mid);
		} else {
			r = mid-1;
		}
	}
	printf("%lld\n", H);
	
	return 0;
}