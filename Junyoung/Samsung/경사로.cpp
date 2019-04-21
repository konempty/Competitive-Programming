// https://www.acmicpc.net/problem/14890

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
			map[j+N][i] = map[i][j]; // 가로 세로 변환
		}
	}
	
    int cnt = 0;
    for (int r = 0; r < 2*N; r++) {
		int flat = 1, c;
		for (c = 0; c < N-1; c++) {
			if (map[r][c] == map[r][c+1]) flat++;
			else if (map[r][c]+1 == map[r][c+1] && flat >= L) flat = 1;
			else if (map[r][c]-1 == map[r][c+1] && flat >= 0) flat = -L+1;
			else break;
		}
		if (c == N-1 && flat >= 0) cnt++;
    }
    printf("%d\n", cnt);
	
    return 0;
}
