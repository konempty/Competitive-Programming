// https://www.acmicpc.net/problem/4948

#include <stdio.h>

using namespace std;

const int MAX_NUM = 123456;
int not_prime[2*MAX_NUM];

// Sieve of Eratosthenes
void set_prime() {
	not_prime[1] = not_prime[0] = true;
	for (int i = 2; i < 2 * MAX_NUM; i++) {
		if (not_prime[i])	continue;

		// eliminate prime i's multiple
		for (int j = i * 2; j < 2 * MAX_NUM; j += i) {
			not_prime[j] = true;
		}
	}
}

int main() {
	set_prime();

	while (1) {
		int t, cnt = 0;
		scanf("%d", &t);

		if (t == 0)	break;
		for (int i = t + 1; i <= 2 * t; i++) {
			if (not_prime[i])	continue;
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}