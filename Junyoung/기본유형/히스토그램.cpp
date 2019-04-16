#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX_N = 100000+1;

int N;
int h[MAX_N+1];
int seg[4*MAX_N];

void seg_init(int nd, int s, int e) {
	if (s == e) {
		// 리프 노드
		seg[nd] = s;
		return;
	}
	int m = (s+e)/2;
	int l = nd*2;
	int r = nd*2 + 1;

	seg_init(l, s, m);
	seg_init(r, m+1, e);
	// 해당 범위 내 최소 높이의 인덱스 저장
	seg[nd] = (h[seg[l]] <= h[seg[r]]) ? seg[l] : seg[r];
}

// [s,e] 구간 내 최소 높이의 인덱스 반환
int query(int s, int e, int nd, int l, int r) {
    if (r < s || e < l)		return -1;
    if (s <= l && r <= e)	return seg[nd];

    int m = (l+r)/2;
	int q1 = query(s, e, nd*2, l, m);
    int q2 = query(s, e, nd*2 + 1, m+1, r);
    
	if (q1 == -1)	return q2;
    if (q2 == -1)	return q1;
	return (h[q1] <= h[q2]) ? q1 : q2;
}
ll sol(int s, int e) {
    int m = query(s, e, 1, 0, N-1);
    
	ll rect = (ll)(e-s+1) * h[m];
    if (s <= m-1) {
		// 최소 높이 인덱스 왼쪽 구간
        rect = max(rect, sol(s, m-1));
    }
    if (m+1 <= e) {
		// 최소 높이 인덱스 오른쪽 구간
        rect = max(rect, sol(m+1, e));
    }
    return rect;
}

int main() {
	while (true) {
		scanf("%d", &N);
		if (!N)	break;

		for (int i = 0; i < N; i++) {
			scanf("%d", &h[i]);
		}
		seg_init(1, 0, N-1);
		printf("%lld\n", sol(0, N-1));
	}
    return 0;
}