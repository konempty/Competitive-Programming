// 국방 오픈소스 아카데미 4번 문항

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;

const int MAXN = 1e5 +2;
const int ALPHA = 26;
int N, Q;
char book[MAXN];
int S[ALPHA+1], E[ALPHA+1];

int main(){
	scanf("%d %d\n", &N, &Q);
	fgets(book, MAXN, stdin);
	
	FORr(i, N-1, 0)	S[book[i]-'A'] = i+1;
	FOR(i, 0, N)	E[book[i]-'A'] = i+1;
	
	FOR(q, 0, Q){
		int s, e;
		int idx = -1;
		int mcnt = 0;
		scanf("%d %d", &s, &e);
		
		FOR(i, 0, ALPHA){
			if(E[i] < s || e < S[i] || !S[i])	continue;
			int cnt = min(E[i], e) - max(S[i], s)+1;
			if(mcnt < cnt){
				mcnt = cnt;
				idx = i;
			}
		}
		printf("%c\n", idx+'A');
	}	
	return 0;
}