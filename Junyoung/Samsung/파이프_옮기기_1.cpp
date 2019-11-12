// https://www.acmicpc.net/problem/17070

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 16+4;
const int dr[] = { 0, 1, 1 };
const int dc[] = { 1, 0, 1 };
const int dd[][3] = { {0,2,MAXN}, {1,2,MAXN}, {0,1,2} };

int N;
int map[MAXN][MAXN];

int dfs(int r, int c, int dir){
	if(r == N-1 && c == N-1)	return 1;
	
	int cnt = 0;
	for(int i = 0; i < 3; i++){
		int nd = dd[dir][i];
		int nr = r + dr[nd];
		int nc = c + dc[nd];
		
		if(nd == MAXN)	continue;
		if(nr >= N || nc >= N || map[nr][nc])	continue;
		if(nd == 2 && (map[nr-1][nc] || map[nr][nc-1]))	continue;
		
		cnt += dfs(nr, nc, nd);
	}
	return cnt;
}

int main(){
	
	scanf("%d", &N);
	FOR(r, 0, N)	FOR(c, 0, N){
		scanf("%d", &map[r][c]);
	}
	printf("%d\n", dfs(0,1,0));
	
	return 0;
}