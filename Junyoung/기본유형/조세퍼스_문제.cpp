// https://www.acmicpc.net/problem/1158

#include <stdio.h>
#include <queue>

using namespace std;

queue <int> q;

int main() {
	int N, M;

	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	int cnt = 0;
	printf("<");
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cnt++;
		if (cnt == M) {
			printf("%d", x);
			if (!q.empty())	printf(", ");
			cnt = 0;
		} else {
			q.push(x);
		}
	}
	printf(">");

	return 0;
}