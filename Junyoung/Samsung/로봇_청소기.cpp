// https://www.acmicpc.net/problem/14503

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;

const int MAXN = 50+2;
// 북 동 남 서
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
// 북서 동북 남동 서남 
const int l_turn[] = {3,0,1,2};

int N, M;
int cnt = 0;
int map[MAXN][MAXN];

void dfs(int r, int c, int dir){
    if (map[r][c] == 1) return;
	if (!map[r][c]){
		map[r][c] = 2;
		cnt++;
	}
	FOR(i, 0, 4){
		dir = l_turn[dir];
		int nr = r + dr[dir];
		int nc = c + dc[dir];
		
		if (!map[nr][nc]){
			dfs(nr, nc, dir);
			return;
		}
	}
	int nr = r - dr[dir];
	int nc = c - dc[dir];
	dfs(nr, nc, dir);
}

int main(){
	int R, C, dir;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &R, &C, &dir);
	FOR(r, 0, N)	FOR(c, 0, M)	scanf("%d", &map[r][c]);
	
	dfs(R, C, dir);
	printf("%d\n", cnt);
    return 0;
}