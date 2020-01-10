// https://www.acmicpc.net/problem/14789

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define FORo(i,o) for(int i = 0, e = o.size(); i < e; i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair <int, int> pii;
typedef priority_queue<int> pqi;

const int MAXLEN = 1e3+2;

string str_in() {
	char input[MAXLEN];
	scanf("%s", input);
	return (string)input;
}

void solve(){
    string cake = str_in();
    int K;	scanf("%d", &K);
    
	int cnt = 0;
	int sz = cake.size();
	FOR(i, 0, sz-K+1){
		if(cake[i] == '-'){
			cnt++;
			FOR(s, i, i+K)	cake[s] = (cake[s] == '+') ? '-' : '+';
		}
	}
	FOR(i, sz-K+1, sz){
		if(cake[i] == '-'){
			printf("IMPOSSIBLE\n");
			return;
		}
	}
	printf("%d\n", cnt);
}

int main(){
	int T;
	scanf("%d ", &T);
	FOR(t, 1, T+1){
	    printf("Case #%d: ", t);
	    solve();
	}
	return 0;
}