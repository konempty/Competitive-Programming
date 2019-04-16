// https://www.acmicpc.net/problem/1992

#include <cstdio>
using namespace std;

const int MAX_N = 64+3;
int N;
int v[MAX_N][MAX_N];

void quad(int r, int c, int size) {
	bool f = false;
	int init = v[r][c];

	for (int i = r; i < r+size && !f; i++) {
		for (int j = c; j < c+size; j++) {
			if (init != v[i][j]) {
				f = true;	break;
			}
		}
	}
	if (!f) {
		printf("%d", init);	return;
	}
	printf("(");
	size /= 2;
	quad(r, c, size);
	quad(r, c+size, size);
	quad(r+size, c, size);
	quad(r+size, c+size, size);
	printf(")");
}

int main() {
	scanf("%d ", &N);
	for (int i = 1; i <= N; i++) {
		char in[MAX_N];
		fgets(in, MAX_N, stdin);
		for (int j = 1; j <= N; j++) {
			v[i][j] = in[j-1]-'0';
		}
	}
	quad(1, 1, N);
	
	return 0;
}