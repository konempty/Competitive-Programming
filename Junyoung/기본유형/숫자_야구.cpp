// https://www.acmicpc.net/problem/2503

#include <stdio.h>

using namespace std;

const int MAX_N = 100;

int N;
int in[MAX_N][5];
int cnt = 0;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &in[i][0], &in[i][3], &in[i][4]);
		in[i][2] = in[i][0] % 10;
		in[i][1] = in[i][0] % 100 / 10;
		in[i][0] = in[i][0] / 100;
	}
	for (int t = 123; t <= 987; t++) {
		int x[] = { t/100, t%100/10, t%10 };

		if (!x[0] || !x[1] || !x[2])	continue;
		if (x[0]==x[1] || x[1]==x[2] || x[2]==x[0]) continue;

		int i;
		for (i = 0; i < N; i++) {
			int s = 0, b = 0;

			if (x[0] == in[i][0])	s++;
			else if (x[0] == in[i][1] || x[0] == in[i][2])	b++;
			if (x[1] == in[i][1])	s++;
			else if (x[1] == in[i][0] || x[1] == in[i][2])	b++;
			if (x[2] == in[i][2])	s++;
			else if (x[2] == in[i][0] || x[2] == in[i][1])	b++;

			if (in[i][3] != s || in[i][4] != b)	break;
		}
		cnt += (i == N);
	}
	printf("%d", cnt);

	return 0;

}