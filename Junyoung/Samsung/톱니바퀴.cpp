// https://www.acmicpc.net/problem/14891

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define FORs(i,s,o) for(int i = s, e = o.size(); i < e; i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 8;
vector<deque<int>> gear(4, deque<int>(8));

void solve(int R, int dir) {

}

void rotate(int R, int dir) {
	if (dir == 1) {
		int tooth = gear[R].back();
		gear[R].pop_back();
		gear[R].push_front(tooth);
	} else {
		int tooth = gear[R].front();
		gear[R].pop_front();
		gear[R].push_back(tooth);
	}
}

string get_str() {
	char input[MAXN+2];
	fgets(input, MAXN+2, stdin);
	input[strlen(input) - 1] = NULL;
	return (string)input;
}

int main() {
	FOR(r, 0, 4) {
		string input = get_str();
		FORs(c, 0, input)	gear[r][c] = input[c]-'0';
	}

	int K;
	scanf("%d", &K);
	FOR(i, 0, K) {
		int R, A;
		scanf("%d %d", &R, &A);
		solve(R, A);
	}
	int sum = 0;
	FOR(i, 0, 4)	sum += (gear[i][0] == 0) ? 0 : (1 << i);
	printf("%d\n", sum);

	return 0;
}