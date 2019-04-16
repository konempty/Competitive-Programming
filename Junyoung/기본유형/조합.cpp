// https://www.acmicpc.net/problem/2407

#include <stdio.h>

using namespace std;

const long long MAX = 1e17;
const int MAX_N = 100+1;

typedef struct longlonglong {
	long long high = 0;
	long long low = 0;
}lll;

lll operator + (lll a, lll b) {
	lll sum;

	sum.high = a.high + b.high;
	if (a.low + b.low > MAX) {
		sum.low = a.low + b.low - MAX;
		sum.high++;
	} else {
		sum.low = a.low + b.low;
	}
	return sum;
}

lll dp[MAX_N][MAX_N];

lll comb(int n, int k) {
	if (n == 0 || k == 0 || n == k) {
		dp[n][k].low = 1;
		return dp[n][k];
	} else if (dp[n][k].low != 0 || dp[n][k].high != 0) { 
		return dp[n][k];
	} else {
		return dp[n][k] = comb(n-1, k-1) + comb(n-1, k);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	m = (m > n-m) ? n-m : m;
	lll temp = comb(n, m);
	
	if (temp.high != 0)
		printf("%lld", temp.high);
	printf("%lld", temp.low);
	return 0;
}