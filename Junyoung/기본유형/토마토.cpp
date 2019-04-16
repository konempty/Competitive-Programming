// https://www.acmicpc.net/problem/7576

#include <stdio.h>
#include <queue>

using namespace std;

class Tomato {
public:
	int r, c;
	Tomato(int _r, int _c) {
		r = _r, c = _c;
	}
};

const int MAX_N = 1000 + 2;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };

int M, N;
int tomato[MAX_N][MAX_N];
int rem = 0, day = 0;
queue <Tomato> q;

void enque(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= M)	continue;
		if (tomato[nr][nc] == 0) {
			tomato[nr][nc] = 1;
			q.push(Tomato(nr, nc));
			rem--;
		}
	}
}

int main() {
	// 1: 익은 토마토
	// 0: 익지 않은 토마토
	// -1: 토마토 없음
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1)	q.push(Tomato(i, j));
			else if (tomato[i][j] == 0)	rem++;
		}
	}
	while (!q.empty() && rem > 0) {
		day++;
		int len = q.size();
		for (int i = 0; i < len; i++) {
			Tomato t = q.front();
			q.pop();
			enque(t.r, t.c);
		}
	}
	printf("%d", (rem == 0) ? day : -1);

	return 0;
}