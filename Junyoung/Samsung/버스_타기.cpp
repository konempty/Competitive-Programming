#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;

const int MAXN = 200000+2;
int A[MAXN];

int main(){
	int T;
	
	scanf("%d", &T);
	FOR(t, 1, T+1){
		int N, K;
		
		scanf("%d %d", &N, &K);		
		FOR(n, 0, N)	scanf("%d", &A[n]);
		sort(A, A+N);
		
		int cnt = 1;
		FOR(a, 1, N){
			cnt += (A[a] - A[a-cnt] <= K);
		}
		printf("Case #%d\n%d\n", t, cnt);
	}
	return 0;
}