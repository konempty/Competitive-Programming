#include <cstdio>

using namespace std;

const int MAX_N = 500000;

typedef long long ll;
int N;
int A[MAX_N];
int B[MAX_N];

ll solve(int s, int e) {
    if (s == e) return 0;
    int m = (s + e) / 2;

    ll ans = solve(s, m) + solve(m+1, e);

    int i = s;
    int j = m + 1;
    int k = 0;

    while (i <= m || j <= e){
        if (i <= m && (j > e || A[i] <= A[j])){
            B[k++] = A[i++];
        } else {
            // 왼쪽 배열의 남아있는 원소들의 개수
            ans += (ll)(m - i + 1);
            B[k++] = A[j++];
        }
    }

    for (int i = s; i <= e; i++) {
        A[i] = B[i - s];
    }
    return ans;
}
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
    printf("%lld", solve(0, N-1));

    return 0;
}