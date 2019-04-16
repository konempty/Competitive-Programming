// https://www.acmicpc.net/problem/2178

#include <stdio.h>
#include <queue>
#define MAXSIZE 100+2

using namespace std;

class Pot {
public:
	int r, c, len;

	Pot(int _r, int _c, int _len) {
		r = _r;
		c = _c;
		len = _len;
	}
};

int dir_r[] = { 0,0,1,-1 };
int dir_c[] = { 1,-1,0,0 };

int N, M;
int maze[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE][MAXSIZE];

int bfs() {
	queue <Pot> q;
	q.push(Pot(1,1,1));
	visited[1][1] = true;

	while (!q.empty()) {
		Pot pot = q.front();
		q.pop();

		if (pot.r == N && pot.c == M)
			return pot.len;

		for (int i = 0; i < 4; i++) {
			int r = pot.r + dir_r[i];
			int c = pot.c + dir_c[i];

			if (r == 0 || r == N+1 || c == 0 || c == M+1)	continue;
			if (visited[r][c])	continue;
			if (maze[r][c] == 0)	continue;

			q.push(Pot(r,c,pot.len+1));
			visited[r][c] = true;
		}
	}
}

int main() {
	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) {
		char input[MAXSIZE];
		fgets(input, MAXSIZE, stdin);
		for (int j = 0; j < M; j++) {
			maze[i+1][j+1] = input[j]-'0';
		}
	}
	printf("%d", bfs());

	return 0;
}