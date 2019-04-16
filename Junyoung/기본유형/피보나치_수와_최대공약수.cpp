// https://www.acmicpc.net/problem/11778
// https://www.cut-the-knot.org/arithmetic/algebra/FibonacciGCD.shtml

#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
const ll mod = 1000000007;

matrix operator * (matrix &A, matrix &B) {
	matrix R(2, vector<ll>(2));

	R[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % mod;
	R[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % mod;
	R[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % mod;
	R[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % mod;

	return R;
}

// A^n = A^(n/2) * A^(n/2)
matrix pow(matrix A, ll n) {
	if (n >= 2) {
		A = pow(A, n/2);	// divide
		A = A * A;			// conquer

		if (n % 2 == 1) {	// odd number
			matrix F = { {1,1}, {1,0} };
			A = A * F;
		}
	}
	return A;
}

ll fibo(ll n) {
	if (n <= 1) return n;
	matrix A = { {1,1}, {1,0} };

	return pow(A, n)[0][1];
}

ll gcd(ll a, ll b) {
	ll m;

	while ((m = a % b) > 0) {
		a = b;
		b = m;
	}
	return b;
}

int main() {
	ll N, M;
	scanf("%lld %lld", &N, &M);
	printf("%lld", fibo(gcd(N,M)));

	return 0;
}