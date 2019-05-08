// https://www.acmicpc.net/problem/9466

#include <cstdio>
#include <vector>
using namespace std;

int N;
vector <int> S;
vector <int> start;
vector <int> cycle_cnt;

int dfs(int n, int first, int cnt){
	if(cycle_cnt[n]){
		// 이미 사이클이 있는 경우
		if(start[n] != first)	return 0;
		// 사이클이 처음 만들어지는 경우
		else return cnt-cycle_cnt[n];
	}
	start[n] = first;
	cycle_cnt[n] = cnt;
	return dfs(S[n], first, cnt+1);
}

int main(){	
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		scanf("%d", &N);
		S = vector<int>(N+1, 0);
		start = vector<int>(N+1, 0);
		cycle_cnt = vector<int>(N+1, 0);
		for(int i = 1; i <= N; i++)	scanf("%d", &S[i]);
		
		int cnt = 0;
		for(int i =1; i <= N; i++){
			cnt += (cycle_cnt[i]) ? 0 : dfs(i, i, 1);
		}
		printf("%d\n", N-cnt);
	}
}
