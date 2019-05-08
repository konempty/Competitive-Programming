#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(int i = s; i < e; i++)
const int MAXN = 100000+2;

ll seq[MAXN];

int main(){
	int N, S;
	
	scanf("%d %d", &N, &S);
	FOR(i, 0, N)	scanf("%lld", &seq[i]);
	
	ll psum = seq[0];
	int len = N+1;
	int l = 0, r = 0;
	
	while(l <= r && r < N){
		if(psum < S){
			psum += seq[++r];
		} else {
			len = min(len, r-l+1);
			psum -= seq[l++];
		}
	}
	printf("%d\n", (len>N) ? 0 : len);
	
	return 0;
}