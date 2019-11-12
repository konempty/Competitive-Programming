#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)

const int MAXN = 1000 +2;

int N, M;
int map[MAXN][MAXN];

int main(){
	scanf("%d %d", &N, &M);
	vector<int> cnt(N, 0);
	
	FOR(i, 1, N+1){
		int L, R, B, T;
		scanf("%d %d %d %d", &L, &R, &B, &T);
		FOR(r, B, T+1)	FOR(c, L, R+1)	map[r][c] = i;
	}
	FOR(i, 1, M+1){
		int x, y;	scanf("%d %d", &x, &y);
		int p = map[y][x];
		cnt[p]++;
	}
	FOR(i, 1, N+1){
		printf("Button #%d: %d\n", i, cnt[i]);
	}
	
	return 0;
}