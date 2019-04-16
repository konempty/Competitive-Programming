// http://tech.kakao.com/2017/09/27/kakao-blind-recruitment-round-1/

#include <cstdio>
#include <vector>
using namespace std;

const int MAXSIZE = 30+2;
const int dr[] = {0, 0, 1, 1};
const int dc[] = {0, 1, 0, 1};

char map[MAXSIZE][MAXSIZE];
bool erase[MAXSIZE][MAXSIZE];
int cnt = 0;

bool check4(int r, int c){
	for(int i = 1; i < 4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(map[r][c] != map[nr][nc]) return false;
	}
	for(int i = 0; i < 4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		erase[nr][nc] = true;
	}
	return true;
}

int main() {
	int M, N;
	
	scanf("%d %d ", &M, &N);
	for(int i = 0; i < M; i++){
		fgets(map[i], MAXSIZE, stdin);
	}
	
	bool has_4 = true;
	while(true){
		// add 2x2 sets to erase list
		has_4 = false;
		for(int r = 0; r < M; r++){
			for(int c = 0; c < N; c++){
				if(check4(r,c))	has_4 = true;
			}
		}
		if(!has_4)	break;
		
		// erase blocks
		for(int r = 0; r < M; r++){
			for(int c = 0; c < N; c++){
				if(!erase[r][c])	continue;
				erase[r][c] = false;
				map[r][c] = '*';
				cnt++;
			}
		}
		// drop blocks
		for(int c = 0; c < N; c++){
			for(int r = M-2; r >=0; r--){
				if(map[r][c] != '*')	continue;
				
				int ob;
				for(ob = r-1; ob >= 0; ob--){
					if(map[ob][c] != '*')	break;
				}
				// 여기 처리해줘야 함!
				// https://globaldino.tistory.com/19
				map[r][c] = map[ob][c];
				map[ob][c] = '*';
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}