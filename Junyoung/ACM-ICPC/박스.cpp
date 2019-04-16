// https://www.acmicpc.net/problem/9455

#include <stdio.h>
#define MAX_M 100
#define FILLED 1

using namespace std;

int grid[MAX_M][MAX_M];
int M, N;

int main() {
	int T;
	
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int move = 0;

		scanf("%d %d", &M, &N);
		for (int r = 0; r < M; r++) {
			for (int c = 0; c < N; c++) {
				scanf("%d", &grid[r][c]);
			}
		}

		for (int c = 0; c < N; c++) {
			int r_pos = M-1;
			for (int r = M-1; r >= 0; r--) {
				if (grid[r][c] != FILLED)	continue;
				if (r < M-1) {
					move += r_pos - r;
				}
				r_pos--;
			}
		}
		printf("%d\n", move);
	}
	return 0;
}