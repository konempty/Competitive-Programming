#include <cstdio>
#include <cmath>
using namespace std;

int N, R, C;
int cnt = 0;

void dnc(int r, int c, int n) {
	if (r == R && c == C) {
		printf("%d\n", cnt);
		return;
	}
	if (r <= R && R < r+n && c <= C && C < c+n) {
		n /= 2;
		dnc(r, c, n);
		dnc(r, c+n, n);
		dnc(r+n, c, n);
		dnc(r+n, c+n, n);
		return;
	}
	cnt += n * n;
}

int main() {
	scanf("%d %d %d", &N, &R, &C);
	N = pow(2, N);
	dnc(0, 0, N);

    return 0;
}