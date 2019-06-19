// https://www.acmicpc.net/problem/14502

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
typedef pair<int,int> pii;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int MAXN = 8+2;

int N, M;
int map[MAXN][MAXN];
int temp[MAXN][MAXN];
vector<pii> q;

void spread(int r, int c){
	temp[r][c] = 1;
	FOR(i, 0, 4){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr < 0 || nr >= N || nc < 0 || nc >= M)	continue;
		if(temp[nr][nc])	continue;
		spread(nr, nc);
	}
}

int main(){
	scanf("%d %d", &N, &M);
	FOR(r, 0, N)	FOR(c, 0, M){
		scanf("%d", &map[r][c]);
		if(map[r][c]==0)	q.push_back({ r,c });
	}
	
	int max_cnt = 0;
	int len = q.size();
	FOR(a, 0, len)	FOR(b, a+1, len)	FOR(c, b+1, len){
		// set
		FOR(r, 0, N)	FOR(c, 0, M)	temp[r][c] = map[r][c];
		temp[q[a].first][q[a].second] = 1;
		temp[q[b].first][q[b].second] = 1;
		temp[q[c].first][q[c].second] = 1;
		// dfs
		FOR(r, 0, N)	FOR(c, 0, M)	if(temp[r][c] == 2)	spread(r, c);
		// count
		int cnt = 0;
		FOR(r, 0, N)	FOR(c, 0, M)	cnt += (temp[r][c] == 0);
		max_cnt = max(cnt, max_cnt);
	}
	printf("%d\n", max_cnt);
	
	return 0;
}