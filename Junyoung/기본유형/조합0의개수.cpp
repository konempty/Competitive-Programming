// https://www.acmicpc.net/problem/2004

#include <stdio.h>
#include <algorithm>

using namespace std;

int count_num(int n, int num) {
	int cnt = 0;

	while (n >= num) {
		cnt += (n /= num);
	}
	return cnt;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int five_cnt = count_num(N, 5) - count_num(M, 5) - count_num(N - M, 5);
	int two_cnt = count_num(N, 2) - count_num(M, 2) - count_num(N - M, 2);

	printf("%d", min(five_cnt, two_cnt));
	return 0;
}