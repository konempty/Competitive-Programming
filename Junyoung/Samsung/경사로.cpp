// // https://www.acmicpc.net/problem/14890

#include <cstdio>
using namespace std;

const int MAXN = 100 + 2;
int main() {
	int N, L;
    int map[2*MAXN][MAXN];
	
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
    for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			map[i+N][j] = map[j][i];
		}
	}
	
    int cnt = 0;
    for (int i = 0; i < 2*N; i++) {
		int c = 1, j;
		for (j = 0; j < N-1; j++) {
			if (map[i][j] == map[i][j+1]) c++;
			else if (map[i][j]+1 == map[i][j+1] && c >= L) c = 1;
			else if (map[i][j]-1 == map[i][j+1] && c >= 0) c = -L+1;
			else break;
		}
		if (j == N-1 && c >= 0) cnt++;
    }
    printf("%d\n", cnt);
	
    return 0;
}
