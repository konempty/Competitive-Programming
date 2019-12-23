#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define FORo(i,e,o) for(int i = 0, e = o.size(); i < e; i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair <int, int> pii;
typedef priority_queue<int> pqi;

const int MAXN = 2e5 + 2;

int N, group, cable;
int com[MAXN];
vector<bool> visit;

void init() {
	scanf("%d", &N);
	FOR(i, 0, N) scanf("%d", &com[N-1-i]);
	visit.assign(N, false);
	group = 0, cable = 0;
}

void solve() {
	FOR(c, 0, N) {
		if (!com[c]) {
			if (!visit[c]) {
				group++;
				visit[c] = true;
			}
			continue;
		}

		bool has_group = false;
		for (int n = c+1, cnt = 0; n < N && cnt < 5; n++) {
			if (com[n])	continue;
			has_group = has_group || visit[n];
			visit[n] = true;
			cnt++;
			cable += n-c;
		}
		group += !has_group;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	FOR(t, 1, T+1) {
		init();
		solve();
		printf("#%d %d %d\n", t, cable, group);
	}
	return 0;
}