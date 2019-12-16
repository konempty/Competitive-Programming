// https://www.acmicpc.net/problem/15683

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORo(i,e,o) for(int i = 0, e = o.size(); i < e; i++)

typedef struct {
	int r, c, type;
} pot;
const int MAXN = 8+2;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0, -1 };

int rem = MAXN*MAXN +1;
int N, M;
int map[MAXN][MAXN];
int tmap[MAXN][MAXN];
vector<pot> cctv;
vecotr<int> angle;

void copy(){
	FOR(r, 0, N) FOR(c, 0, M){
		tmap[r][c] = map[r][c];
	}
}

int blind_count(){
	int cnt = 0;
	FOR(r, 0, N) FOR(c, 0, M)	cnt += (tmap[r][c] == 0);
	return cnt;
}

vector<vector<int>> angle_list(int type) {
	switch (type) {
	case 1:	return { {0},{1},{2},{3} };
	case 2:	return { {0,2},{1,3} };
	case 3:	return { {0,1},{1,2},{2,3},{3,0} };
	case 4:	return { {0,1,2},{1,2,3},{2,3,0},{3,0,1} };
	case 5:	return { {0,1,2,3} };
	}
}

void dfs(int idx){
	int len = cctv.size();
	if(idx == len) {
		copy();
		// cctv 하나씩
		FOR(i, 0, len) {
			int r = cctv[i].r, c = cctv[i].c;
			// 방향 유형 & 1개 방향 선택
			vector<int> dir_list = angle_list(cctv[i].type)[angle[i]];
			FORo(v, o, dir_list) {
				int nr = r, nc = c;
				while (true) {
					int dir = dir_list[v];
					nr += dr[dir];	nc += dc[dir];
					if (nr < 0 || nr >= N || nc < 0 || nc >= M)	break;
					if(tmap[nr][nc] == 6)	break;
					if(tmap[nr][nc])	continue;
					tmap[nr][nc] = 9;
				}
			}
		}
		rem = min(rem, blind_count());
		return;
	}
	
	int sz = (cctv[idx].type == 2) ? 2 : (cctv[idx].type == 5) ? 1: 4;
	FOR(i, 0, sz) {
		angle.push_back(i);
		dfs(idx+1);
		angle.pop_back();
	}
}

int main(){
	scanf("%d %d", &N, &M);
	FOR(r, 0, N) FOR(c, 0, M) {
		scanf("%d", &map[r][c]);
		if(map[r][c] && map[r][c] < 6)
			cctv.push_back({ r,c,map[r][c] });
	}
	dfs(0);
	printf("%d\n", rem);
	return 0;
}