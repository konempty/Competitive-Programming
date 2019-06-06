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
int price[MAXN];

void solve(int t){
	int N;
	scanf("%d", &N);
	FOR(n, 0, N)	scanf("%d", &price[n]);
	
	int cnt = 0;
	FOR(i, 0, N){
		for(; i < N && price[i] >= price[i+1]; i++);
		if(i >= N-1)	break;
		cnt++;
		
		for(; i < N-1 && price[i] <= price[i+1]; i++);
		cnt++;
	}
	printf("Case #%d\n%d\n", t, cnt);
}

int main(){
	int T;
	scanf("%d ", &T);
	FOR(t, 1, T+1)	solve(t);
	return 0;
}