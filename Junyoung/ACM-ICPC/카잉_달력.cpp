// https://www.acmicpc.net/problem/6064

#include <stdio.h>

using namespace std;

int get_lcm(int a, int b) {
	int mod, result = a * b;

	while ((mod = a % b) > 0) {
		a = b;
		b = mod;
	}
	return result/b;
}

int main() {
	int T;

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int M, N, x, y;
		scanf("%d %d %d %d", &M, &N, &x, &y);

		int max_year = get_lcm(M, N);

		while ((x - 1) % N + 1 != y) {
			if (x > max_year) {
				x = -1;
				break;
			}
			x += M;
		}
		printf("%d\n", x);
	}
	return 0;
}