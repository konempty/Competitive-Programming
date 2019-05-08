// https://www.acmicpc.net/problem/14500

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

const int MAXN = 500+2;
const int dr[] = {0,0,-1,1};
const int dc[] = {1,-1,0,0};

int N, M;
int max_val = 0;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];

void dfs(int r, int c, int cnt, int sum){
	if(cnt == 4){
		max_val = max(max_val, sum);
		return;
	}
	FOR(i, 0, 4){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr < 0 || nr >= N || nc < 0 || nc >= M)	continue;
		if(visited[nr][nc])	continue;
		
		visited[nr][nc] = true;
		dfs(nr, nc, cnt+1, sum + map[nr][nc]);
		visited[nr][nc] = false;
	}
}
void check_T(int r, int c){
	FOR(t, 0, 4){
		int sum = map[r][c];
		bool cant = false;
		FOR(i, 0, 3){
			int nr = r + dr[(t+i)%4];
			int nc = c + dc[(t+i)%4];
			if(nr < 0 || nr >= N || nc < 0 || nc >= M) {
				cant = true;
				break;
			}
			sum += map[nr][nc];
		}
		max_val = cant ? max_val : max(max_val, sum);
	}
}

int main(){
	scanf("%d %d", &N, &M);
	FOR(r, 0, N)	FOR(c, 0, M)	scanf("%d", &map[r][c]);
	FOR(r, 0, N)	FOR(c, 0, M) {
		visited[r][c] = true;
		dfs(r, c, 1, map[r][c]);
		check_T(r,c);
		visited[r][c] = false;
	}
	printf("%d\n", max_val);
	
	return 0;
}