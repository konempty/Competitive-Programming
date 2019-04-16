// https://www.acmicpc.net/problem/13567
// 방향 전환

#include <cstdio>
#include <algorithm>

using namespace std;

// 동 서 남 북
const int dr[] = {0,0,-1,1};
const int dc[] = {1,-1,0,0};
// 북남, 남북, 동서, 서동
const int TURN[4][2] = {{3,2},{2,3},{0,1},{1,0}};

int dir = 0;
int r, c;

int main() {
	int M, N;
	
	scanf("%d %d ", &M, &N);
	for(int i =0; i < N; i++){
		char op[10];
		int cnt;
		
		scanf("%s %d", op, &cnt);
		if(op[0] == 'M'){
			r += dr[dir] * cnt;
			c += dc[dir] * cnt;
			
			if(r < 0 || r > M || c < 0 || c > M)	return !printf("-1");
		} else {
			dir = TURN[dir][cnt];
		}
	}
	printf("%d %d", c, r);
	return 0;
}