// https://www.acmicpc.net/problem/8911
// 방향 전환

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXSIZE = 500+2;
// 북동남서
const int dir_r[] = { -1, 0, 1, 0 };
const int dir_c[] = { 0, 1, 0, -1 };


int main() {
	int T;
	scanf("%d ", &T);
	for(int t = 0 ; t < T; t++){
		char move[MAXSIZE];
		fgets(move, MAXSIZE, stdin);
		
		int r = 0, c = 0, dir = 0;
		int max_r = r, max_c = c;
		int min_r = r, min_c = c;
		
		int len = strlen(move)-1;
		for(int i = 0; i < len; i++){
			switch(move[i]){
				case 'F':
					r += dir_r[dir];
					c += dir_c[dir];
					break;
				case 'B':
					r -= dir_r[dir];
					c -= dir_c[dir];
					break;
				case 'L':
					dir = (dir+3)%4;
					break;
				case 'R':
					dir = (dir+1)%4;
					break;
			}
			// printf("%d %d\n", r, c);
			max_r = max(r, max_r);	max_c = max(c, max_c);
			min_r = min(r, min_r);	min_c = min(c, min_c);
		}
		int rect = (max_r - min_r) * (max_c - min_c);
		// printf("%d\n", dir);
		printf("%d\n", rect);
	}
	return 0;
}
