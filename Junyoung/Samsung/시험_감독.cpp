// https://www.acmicpc.net/problem/13458

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;

const int MAXN = 1e6 + 2;
int A[MAXN];

int main(){
	int N, B, C;
	
	scanf("%d", &N);
	FOR(n, 0, N)	scanf("%d", &A[n]);
	scanf("%d %d", &B, &C);
	
	ll sum = N;
	FOR(n, 0, N){
		if((A[n] -= B) < 0)	continue;
		sum += A[n]/C + ((A[n]%C) ? 1 : 0);
	}
	printf("%lld\n", sum);
	return 0;
}