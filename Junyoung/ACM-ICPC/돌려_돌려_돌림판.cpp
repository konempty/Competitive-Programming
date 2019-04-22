// https://www.acmicpc.net/problem/11504

#include <cstdio>
#include <string>
using namespace std;

const int MAXN = 100+2;
const int MAXM = 9+2;

int main() {
	int T;
	
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		int N, M;
		int X=0, Y=0;
		int wheel[MAXN];
		
		scanf("%d %d", &N, &M);
		for(int in, i = 0; i < M; i++){
			scanf("%d", &in);
			X = X*10 + in;
		}
		for(int in, i = 0; i < M; i++){
			scanf("%d", &in);
			Y = Y*10 + in;
		}
		for(int i = 0; i < N; i++)	scanf("%d", &wheel[i]);
		
		int cnt = 0;
		for(int n = 0; n < N; n++){	// M 자리 수 추출 from N
			int Z = 0;
			for(int m = 0; m < M; m++){
				Z = Z*10 + wheel[(n+m)%N];
			}
			cnt += (X <= Z && Z <= Y);
		}
		printf("%d\n", cnt);
	}
    return 0;
}
