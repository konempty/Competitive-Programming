// https://www.acmicpc.net/problem/12100

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;

// 북 동 남 서
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int N;
int max_val = 0;

int dfs(vector<vector<int>> map, int cnt){
	int ret = 0;
	
	FOR(r, 0, N)	FOR(c, 0, N)
		ret = max(ret, map[r][c]);
	
	if(cnt == 5)	return max(ret, max_val);
	if(ret << 5-cnt <= max_val)	return max_val;
	
	vector<vector<int>> bef(N, vector<int>(N));
	FOR(d, 0, 4){
		switch(d){
			case 0:	// 270 rotate
				FOR(r, 0, N)	FOR(c, 0, N){
					bef[N-1-c][r] = map[r][c];
				}
				break;
			case 1:	// col flip
				FOR(r, 0, N)	FOR(c, 0, N){
					bef[r][N-1-c] = map[r][c];
				}
				break;
			case 2:	// 90 rotate
				FOR(r, 0, N)	FOR(c, 0, N){
					bef[c][N-1-r] = map[r][c];
				}
				break;
			case 3:	// origin
				FOR(r, 0, N)	FOR(c, 0, N){
					bef[r][c] = map[r][c];
				}
				break;
		}
		vector<vector<int>> aft(N, vector<int>(N));
		copy(ALL(bef), aft.begin());
		
		FOR(r, 0, N) {
			queue <int> q;
			FOR(c, 0, N){
				if(!bef[r][c])	continue;
				q.push(bef[r][c]);
				bef[r][c] = 0;
			}
			int c = 0;
			while(!q.empty()){
				int val = q.front();
				q.pop();
				if(!bef[r][c]){
					bef[r][c] = val;
				} else if(bef[r][c] == val){
					bef[r][c++] *=2;
				} else {
					bef[r][++c] = val;
				}
			}
		}
		if(bef == aft)	continue;
		ret = max(ret, dfs(bef, cnt+1));
	}
	return ret;
}

int main(){
	vector <vector<int>> map;
	
	scanf("%d", &N);
	map = vector<vector<int>> (N, vector<int>(N));
	
	FOR(r, 0, N)	FOR(c, 0, N)	scanf("%d", &map[r][c]);
	printf("%d\n", dfs(map, 0));
	
	return 0;
}