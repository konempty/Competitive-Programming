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
const int MAXP = 1e9+2;
int price[MAXN];

void solve(){
	int N;
	scanf("%d", &N);
	FOR(n, 1, N+1)	scanf("%d", &price[n]);
	price[0] = MAXP;	price[N+1] = -MAXP;
	
	int cnt = 0;
	FOR(i, 1, N+1){
		for(; i < N && price[i-1] > price[i]; i++);
		cnt++;
		if(i == N)	break;
		
		for(; i < N && price[i-1] < price[i]; i++);
		cnt++;
	}
	printf("%d\n", cnt);
}

int main(){
	int T;
	scanf("%d ", &T);
	FOR(t, 1, T+1){
		printf("Case #%d\n", t);
		solve();
	}
	return 0;
}