// https://www.acmicpc.net/problem/11070

#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;


int main() {
	int T;

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int n, m;
		vector <pair<int, int>> team;

		scanf("%d %d", &n, &m);
		team.resize(n + 1, {0,0});
		for (int i = 0; i < m; i++) {
			int a, b, p, q;
			scanf("%d %d %d %d", &a, &b, &p, &q);
			team[a].first += p;	team[a].second += q;
			team[b].first += q;	team[b].second += p;
		}

		double min = 1, max = 0;
		for (int i = 1; i <= n; i++) {
			double w = 0;
			if (team[i].first || team[i].second) {
				w = pow(team[i].first, 2) / (pow(team[i].first, 2) + pow(team[i].second, 2));
			}
			max = (max < w) ? w : max;
			min = (min > w) ? w : min;
		}
		printf("%d\n%d\n", (int)(max*1000), (int)(min*1000));
	}
	return 0;
}