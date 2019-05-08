#include <cstdio>
#include <vector>
using namespace std;

#define FOR(i,s,n) for(int i = s; i < n; i++)
const int MAXM = 500*1000;

vector <vector <int>> edge(MAXM);
bool visited[MAXM];
int cnt = 0;

void dfs(int n){
	visited[n] = true;
	
	int len = edge[n].size();
	FOR(i, 0, len){
		int next = edge[n][i];
		if(visited[next])	continue;
		dfs(next);
	}
}

int main(){
	int N, M;
	
	scanf("%d %d", &N, &M);
	FOR(i, 0, M){
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	FOR(i, 1, N+1){
		if(visited[i])	continue;
		cnt++;
		dfs(i);
	}
	printf("%d\n", cnt);
	
	return 0;
}