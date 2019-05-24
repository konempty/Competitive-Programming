// https://www.acmicpc.net/problem/2573

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
typedef pair<int,int> pii;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int MAXN = 300+2;

int N, M;
int map[MAXN][MAXN];
int bound[MAXN][MAXN];
vector <vector<int>> visited;
queue<pii> q;

int bound_cnt(int r, int c){
	int cnt = 0;
	FOR(i, 0, 4){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr < 0 || nr >= N || nc < 0 || nc >= M)	continue;
		cnt += (map[nr][nc] == 0);
	}
	return cnt;
}
void dfs(int r, int c){
	visited[r][c] = true;
	FOR(i, 0, 4){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr < 0 || nr >= N || nc < 0 || nc >= M)	continue;
		if(visited[nr][nc])	continue;
		dfs(nr,nc);
	}
}

int main(){
	scanf("%d %d", &N, &M);
	FOR(r, 0, N)	FOR(c, 0, M){
		scanf("%d", &map[r][c]);
		if(map[r][c])	q.push({ r,c });
	}
	
	int year = 0;
	bool flag = false;
	while(!q.empty()){
		year++;
		visited = vector<vector<int>> (N,vector<int>(M,0));
		
		while(!q.empty()){
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			bound[r][c] = bound_cnt(r,c);
		}
		FOR(r, 0, N)	FOR(c, 0, M){
			map[r][c] = max(map[r][c]-bound[r][c], 0);
			if(map[r][c])	q.push({ r,c });
		}
		
		int cnt = 0;
		FOR(r, 0, N)	FOR(c, 0, M){
			if(!map[r][c] || visited[r][c])	continue;
			dfs(r,c);
			cnt++;
		}
		if (cnt > 1)	return !printf("%d\n", year);
	}
	return !printf("0\n");
}