// https://www.acmicpc.net/problem/13460

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define FORo(i,e,o) for(int i = 0, e = o.size(); i < e; i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef struct {
	int r,c;
}ball;
typedef struct {
	ball red, blue;
	int dist;
}state;
const int MAXN = 10 +2;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0, -1 };

int N, M;
char board[MAXN][MAXN];
bool visit[MAXN][MAXN][MAXN][MAXN];	// state 중복성 체크 (1e4)

ball bmove(ball b, int d){
	int nr = b.r, nc = b.c;
	while(true){
		nr += dr[d];	nc += dc[d];
		switch(board[nr][nc]){
			case '#':	return { nr-dr[d], nc-dc[d] };
			case 'O':	return { nr, nc };
		}
	}
}

int bfs(ball rb, ball bb){
	int ans = -1;
	queue<state> q;
	
	q.push({ rb,bb,0 });
	visit[rb.r][rb.c][bb.r][bb.c] = true;
	while(!q.empty()){
		state s = q.front();	q.pop();
		
		if(s.dist > 10)	break;
		if(board[s.red.r][s.red.c] == 'O'){
			ans = s.dist;
			break;
		}
		FOR(i, 0, 4){
			ball red = s.red, blue = s.blue;
			
			red = bmove(red, i);	blue = bmove(blue, i);
			if(board[blue.r][blue.c] == 'O')	continue;
			if(red.r == blue.r && red.c == blue.c){
				// 순서 재배치
				switch(i){
					case 0:	s.red.r < s.blue.r ? blue.r++ : red.r++;	break;
					case 1:	s.red.c < s.blue.c ? red.c-- : blue.c--;	break;
					case 2:	s.red.r < s.blue.r ? red.r-- : blue.r--;	break;
					case 3:	s.red.c < s.blue.c ? blue.c++ : red.c++;	break;
				}
			}
			if(!visit[red.r][red.c][blue.r][blue.c]){
				q.push({ red, blue, s.dist+1 });
				visit[red.r][red.c][blue.r][blue.c] = true;
			}
		}
	}
	return ans;
}

int main(){
	freopen("input.txt", "r", stdin);
	
	while(scanf("%d %d ", &N, &M) != EOF){
		ball rb, bb;
		FOR(r, 0, N){
			fgets(board[r], MAXN, stdin);
			board[r][strlen(board[r])-1] = '\0';
			FOR(c, 0, M){
				switch(board[r][c]){
					case 'R': rb = { r,c };	break;
					case 'B': bb = { r,c };	break;
				}
			}
		}
		FOR(a, 0, MAXN)	FOR(b, 0, MAXN)	FOR(c, 0, MAXN)	FOR(d, 0, MAXN)
			visit[a][b][c][d] = false;
		printf("%d\n", bfs(rb,bb));
	}
	return 0;
}